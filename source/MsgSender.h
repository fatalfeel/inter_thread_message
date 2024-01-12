#ifndef DVR_CONNECT_H
#define DVR_CONNECT_H

class MsgSender 
{
public:
	MsgSender();
	~MsgSender();

	void ConnectEvent();
	void DisConnectEvent();
	void TestEvent();
};


#endif /// end of DVR_CONNECT_H

