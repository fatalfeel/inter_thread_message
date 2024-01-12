#ifndef DVR_PLUGIN_H
#define DVR_PLUGIN_H

class DvrPlugin
{
public:
	DvrPlugin();
	~DvrPlugin();
		
	/// event handlers
	void OnStatusConnect(EventPack* evt);
	void OnStatusTest2(EventPack* evt);
	void OnStatusDisconnect(EventPack* evt);
};

#endif
