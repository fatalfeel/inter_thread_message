#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

class EventManager
{
public:
    enum {
        EVENTMGR_CONNECT,
        EVENTMGR_DISCONNECT,
        EVENTMGR_SEND
    };
	
	typedef std::vector<EventFunctorBase<EventPack>*>	EventMessageSlot_Vector;
	/*<message ID, EventPack Vector>*/
	typedef std::map<int, EventMessageSlot_Vector>		EventMessageSlot_Map;

    static EventManager* Get();
    static void Free();
	EventManager();
	~EventManager();

	// event sinks
	void    ProcessEvent(int type, int messageID, EventFunctorBase<EventPack>* functor, void* classptr, EventPack* event);
    void    ConnectEventSlot(int messageID, EventFunctorBase<EventPack>* functor);
    void    DisconnectEventSlot(void* classptr);
	void	SendEventMessage(EventPack* event);
	void	SetShutDown(bool state); 
	int		GetShotDown();
	
	
private:
	// event sinks
	volatile int			m_bShutDown;
	pthread_mutex_t         m_evtmanager_mutex;
	EventMessageSlot_Map    m_EventMessageSlotMap;
};

#endif /// EVENT_MANAGER_H
