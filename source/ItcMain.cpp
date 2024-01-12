#include <iostream>
#include <vector>
#include <map>

#include "EventFunctor.h"
#include "EventPack.h"
#include "MsgSender.h"
#include "EventManager.h"
#include "DvrPlugin.h"
#include "NasPlugin.h"
#include "TestPlugin.h"

int main(int argc, char* argv[])
{
	DvrPlugin*	plugA	= new DvrPlugin();
	NasPlugin*  plugB   = new NasPlugin();
	TestPlugin* plugC   = new TestPlugin();
	MsgSender*	sender	= new MsgSender();
	
	sender->ConnectEvent();		//send message to All Xxx::OnStatusConnect
	sender->TestEvent();        //send message to All Xxx::OnStatusTest2
	sender->DisConnectEvent();	//send message to All Xxx::OnStatusDisconnect

	delete sender;
	delete plugB; //test middle plugin B first
	delete plugC;
	delete plugA;
	
	EventManager::Free();

	//wait anykey
	std::cout << "hit any key" << std::endl;
    std::cin.get();
	
	return 0;
}

