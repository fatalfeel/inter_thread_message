#ifndef EVENT_PACK_H
#define EVENT_PACK_H

extern int EVT_STATUS_CONNECTED;
extern int EVT_STATUS_DISCONNECTED;
extern int EVT_STATUS_TEST1;
extern int EVT_STATUS_TEST2;
extern int EVT_STATUS_TEST3;

/** Event return form DVR */
class EventPack
{
public:
	EventPack( int messageid );
	~EventPack();
		
	void		SetMessageId( int id );
	int			GetMessageId();
	int			GetStatus();
	void		SetStatus( int status );

public:
	int			m_messageid;
	int			m_status;
	int			m_fileid;
	int			m_channels;
	short		m_port;
};

#endif	/// #define CONNECT_EVENT_H
