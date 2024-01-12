#include <vector>
#include <map>

#include "EventFunctor.h"
#include "EventPack.h"
#include "EventManager.h"
#include "MsgSender.h"

MsgSender::MsgSender()
{
}

MsgSender::~MsgSender()
{
}

void MsgSender::ConnectEvent()
{
	EventPack*	evtA = new EventPack(EVT_STATUS_CONNECTED);

	evtA->m_channels	= 1;
	evtA->m_fileid		= 2;
	evtA->m_port		= 3;
	
	evtA->SetStatus(0);

	EventManager::Get()->SendEventMessage(evtA);

	delete evtA;
}

void MsgSender::DisConnectEvent()
{
	EventPack*	evtB = new EventPack(EVT_STATUS_DISCONNECTED);

	evtB->m_channels	= 4;
	evtB->m_fileid		= 5;
	evtB->m_port		= 6;
	
	evtB->SetStatus(1);

	EventManager::Get()->SendEventMessage(evtB);

	delete evtB;
}

void MsgSender::TestEvent()
{
	EventPack*	evtC = new EventPack(EVT_STATUS_TEST2);

	evtC->m_channels	= 1;
	evtC->m_fileid		= 2;
	evtC->m_port		= 30;
	
	evtC->SetStatus(0);

	EventManager::Get()->SendEventMessage(evtC);

	delete evtC;
}
