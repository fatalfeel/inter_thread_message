#include <vector>
#include <map>
#include "EventFunctor.h"
#include "EventPack.h"
#include "EventManager.h"
#include "NasPlugin.h"

//////////////////////NasPlugin///////////////////////////
NasPlugin::NasPlugin()
{
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_CONNECTED,	    new EventFunctor<NasPlugin, EventPack>(this,&NasPlugin::OnStatusConnect));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_TEST2,		    new EventFunctor<NasPlugin, EventPack>(this,&NasPlugin::OnStatusTest2));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_DISCONNECTED,	new EventFunctor<NasPlugin, EventPack>(this,&NasPlugin::OnStatusDisconnect));
}

NasPlugin::~NasPlugin()
{
	EventManager::Get()->DisconnectEventSlot(this);
}

///////////////////////////////////////////////////////////////////
/// event handlers
void NasPlugin::OnStatusConnect(EventPack* evt)
{
	printf("test connect okB\n");
}

void NasPlugin::OnStatusTest2(EventPack* evt)
{
	printf("test B2\n");
}

void NasPlugin::OnStatusDisconnect(EventPack* evt)
{
	printf("test disconnect okB\n");
}
