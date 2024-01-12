#ifndef TEST_PLUGIN_H
#define TEST_PLUGIN_H

class TestPlugin
{
public:
	TestPlugin();
	~TestPlugin();
		
	/// event handlers
	void OnStatusConnect(EventPack* evt);
	void OnStatusTest2(EventPack* evt);
	void OnStatusDisconnect(EventPack* evt);
};

#endif
