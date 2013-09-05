#pragma once
//¾ö²ß
#include "cocos2d.h"
using namespace cocos2d;

class DecideDelegate
{
public:
	virtual void doSomeThing()=0;

};
class Decide
{
private:

	DecideDelegate *delegate;


public:
	Decide(void);
	~Decide(void);
	inline void setDelegate(DecideDelegate *delegate){this->delegate=delegate;}


};