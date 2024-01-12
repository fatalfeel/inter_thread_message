#include <vector>
#include <map>

#include "EventFunctor.h"
#include "EventPack.h"
#include "EventManager.h"
#include "TestPlugin.h"

//////////////////////TestPlugin///////////////////////////
TestPlugin::TestPlugin()
{
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_CONNECTED,	new EventFunctor<TestPlugin, EventPack>(this,&TestPlugin::OnStatusConnect));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_TEST2,		new EventFunctor<TestPlugin, EventPack>(this,&TestPlugin::OnStatusTest2));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_DISCONNECTED,	new EventFunctor<TestPlugin, EventPack>(this,&TestPlugin::OnStatusDisconnect));
}

TestPlugin::~TestPlugin()
{
	EventManager::Get()->DisconnectEventSlot(this);
}

///////////////////////////////////////////////////////////////////
/// event handlers
void TestPlugin::OnStatusConnect(EventPack* evt)
{
	printf("test connect okC\n");
}

void TestPlugin::OnStatusTest2(EventPack* evt)
{
	printf("test C2\n");
}

void TestPlugin::OnStatusDisconnect(EventPack* evt)
{
	printf("test disconnect okC\n");
}
