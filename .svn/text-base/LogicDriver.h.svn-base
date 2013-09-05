#pragma once
#include "Decide.h"
#include "Execution.h"
#include "cocos2d.h"
using namespace cocos2d;
class LogicDriver  :public DecideDelegate
{
public:

	static LogicDriver *createLogicDriver(CCNode *);
	virtual void doSomeThing();

private:
	LogicDriver(void);
	~LogicDriver(void);
	CCNode *hostNode;
	Decide *myDecide;
	Execution *myExecution;

};

