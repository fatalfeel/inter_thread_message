#include <vector>
#include <map>

#include "EventFunctor.h"
#include "EventPack.h"
#include "EventManager.h"
#include "DvrPlugin.h"

//////////////////////DvrPlugin///////////////////////////
DvrPlugin::DvrPlugin()
{
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_CONNECTED,	    new EventFunctor<DvrPlugin, EventPack>(this,&DvrPlugin::OnStatusConnect));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_TEST2,		    new EventFunctor<DvrPlugin, EventPack>(this,&DvrPlugin::OnStatusTest2));
	EventManager::Get()->ConnectEventSlot(EVT_STATUS_DISCONNECTED,	new EventFunctor<DvrPlugin, EventPack>(this,&DvrPlugin::OnStatusDisconnect));
}

DvrPlugin::~DvrPlugin()
{
	EventManager::Get()->DisconnectEventSlot(this);
}

///////////////////////////////////////////////////////////////////
/// event handlers
void DvrPlugin::OnStatusConnect(EventPack* evt)
{
	printf("test connect okA\n");
}

void DvrPlugin::OnStatusTest2(EventPack* evt)
{
	printf("test A2\n");
}

void DvrPlugin::OnStatusDisconnect(EventPack* evt)
{
	printf("test disconnect okA\n");
}
