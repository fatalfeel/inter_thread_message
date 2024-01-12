#ifndef NAS_PLUGIN_H
#define NAS_PLUGIN_H

class NasPlugin
{
public:
	NasPlugin();
	~NasPlugin();
		
	/// event handlers
	void OnStatusConnect(EventPack* evt);
	void OnStatusTest2(EventPack* evt);
	void OnStatusDisconnect(EventPack* evt);
};

#endif
