#include <vector>
#include <map>
//#include <iostream> //test
#include "EventFunctor.h"
#include "EventPack.h"
#include "EventManager.h"

static EventManager* evtmanager_instance = NULL;

EventManager* EventManager::Get()
{
	if (!evtmanager_instance)
		evtmanager_instance = new EventManager;
	
	return evtmanager_instance;
}

void EventManager::Free()
{
	if( evtmanager_instance )
	{
		delete evtmanager_instance;
		evtmanager_instance = NULL;
	}
}

EventManager::EventManager()
{
    pthread_mutex_init(&m_evtmanager_mutex, NULL);
    this->SetShutDown(false);
}

EventManager::~EventManager()
{
    pthread_mutex_destroy(&m_evtmanager_mutex);
    this->SetShutDown(true);
}

void EventManager::SetShutDown( bool state ) 
{ 
	m_bShutDown = state; 
}

int	EventManager::GetShotDown()
{
	return m_bShutDown;
}

void EventManager::ProcessEvent(int type, int messageID, EventFunctorBase<EventPack>* functor, void* classptr, EventPack* event)
{
    pthread_mutex_lock(&m_evtmanager_mutex);

    unsigned int                        i;
    unsigned int                        vsize;
    unsigned int                        shift_p;
    unsigned int                        remain_size_vit;
    unsigned int                        remain_size_mit;
    EventMessageSlot_Vector::iterator   vit;
    EventMessageSlot_Map::iterator      mit;
    EventMessageSlot_Map::iterator      tmp;

    switch(type)
    {
        case EVENTMGR_CONNECT:
            /*mit = m_EventMessageSlotMap.find(messageID);
            if (mit != m_EventMessageSlotMap.end()) {
                // Key exists, add the functor to the existing vector
                mit->second.push_back(functor);
            } else {
                // Key doesn't exist, create a new entry in the map
                EventMessageSlot_Vector newVector;
                newVector.push_back(functor);
                m_EventMessageSlotMap[messageID] = newVector;

            }*/
            //one line done
            m_EventMessageSlotMap[messageID].push_back(functor);
            break;

        case EVENTMGR_DISCONNECT:
            mit             = m_EventMessageSlotMap.begin();
            remain_size_mit = m_EventMessageSlotMap.size();

            while(remain_size_mit > 0)
            {
                shift_p         = 0;
                remain_size_vit = mit->second.size();

                while(remain_size_vit > 0)
                {
                    if( mit->second[shift_p]->getThis() == classptr )
                    {
                        vit = mit->second.begin() + shift_p;
                        delete *vit;            //*vit is class EventFunctorBase
                        mit->second.erase(vit); //erase slot
                    }
                    else
                    {
                        shift_p++;
                    }

                    remain_size_vit--;
                }

                //empty slot remove
                if( mit->second.size() <= 0 )
                {
                    tmp = mit;
                    //mit++;
                    mit = m_EventMessageSlotMap.erase(tmp);
                }
                else
                {
                    mit++;
                }

                remain_size_mit--;
            }
            //std::cout << remain_size_mit << std::endl; //test
            break;

        case EVENTMGR_SEND:
            if( !this->m_bShutDown )
            {
                mit = m_EventMessageSlotMap.find(event->GetMessageId());
                if( mit != m_EventMessageSlotMap.end() )
                {
                    vsize = mit->second.size();
                    for(i=0; i<vsize; i++)
                        mit->second[i]->callMember(event);
                }
            }
            break;
    }

    pthread_mutex_unlock(&m_evtmanager_mutex);
}

void EventManager::ConnectEventSlot(int messageID, EventFunctorBase<EventPack>* functor)
{
	this->ProcessEvent(EVENTMGR_CONNECT, messageID, functor, NULL, NULL);
}

void EventManager::DisconnectEventSlot(void* classptr)
{
    this->ProcessEvent(EVENTMGR_DISCONNECT, 0, NULL, classptr, NULL);
}

void EventManager::SendEventMessage(EventPack* event)
{
    this->ProcessEvent(EVENTMGR_SEND, 0, NULL, NULL, event);
}
