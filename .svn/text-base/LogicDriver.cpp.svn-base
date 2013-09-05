#include "LogicDriver.h"


LogicDriver::LogicDriver(void)
{
	
	myDecide=new Decide();
	myDecide->setDelegate(this);
	myExecution=new Execution();
}


LogicDriver::~LogicDriver(void)
{
	CC_SAFE_DELETE(myExecution);
	CC_SAFE_DELETE(myDecide);
}
 

 LogicDriver* LogicDriver::createLogicDriver(CCNode *sp)
{
	LogicDriver *ld=new LogicDriver();
ld->hostNode=sp;
ld->myExecution->setHost(sp);
return ld;
}

 void LogicDriver::doSomeThing()
 {

 }
