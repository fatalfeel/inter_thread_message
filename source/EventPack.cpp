#include "EventFunctor.h"
#include "EventPack.h"

int EVT_STATUS_CONNECTED	= 1000;
int EVT_STATUS_DISCONNECTED = 1001;
int EVT_STATUS_TEST1        = 2001;
int EVT_STATUS_TEST2		= 2002;
int EVT_STATUS_TEST3		= 2003;

EventPack::EventPack( int messageid )
{
    m_messageid = messageid;
    m_status    = 0;
    m_fileid    = 0;
    m_channels  = 0;
    m_port      = 0;
}

EventPack::~EventPack()
{
}

void EventPack::SetMessageId( int id ) 
{ 
	m_messageid = id; 
}

int EventPack::GetMessageId() 
{ 
	return m_messageid; 
}

int EventPack::GetStatus() 
{ 
	return m_status; 
}

void EventPack::SetStatus( int status ) 
{ 
	m_status = status; 
}
	
