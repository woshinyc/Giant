#pragma once
#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC;
USING_NS_CC_EXT;
class Execution     //÷¥––
{
private:
	CCNode *hostNode;

public:
	Execution(void);
	~Execution(void);
	inline void setHost(CCNode *node){hostNode=node;}


};

