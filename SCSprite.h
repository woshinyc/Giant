#pragma once
#include "DBaseSprite.h"
#include "cocos2d.h"
using namespace cocos2d;
class SCSprite :public DBaseSprite,public cocos2d::CCTargetedTouchDelegate
{
	private:
	SCSprite(void);
	virtual ~SCSprite(void);
	void(*callback)(int);
	bool initWithFile(const char *,void(*callback)(int));
	bool initWithFile(const char *,CCObject*,SEL_CallFuncN);
	bool initWithTexture(CCTexture2D *pTexture,const CCRect& tRect,CCObject*,SEL_CallFuncN);

	bool containsTouchLocation(CCTouch *touch);
	bool canTouch;

	std::string cardID;
	std::string fileName;

	CCRect rect;
	CCObject *m_pSelectorTarget;
	SEL_CallFuncN  m_pCallFuncN;

public:
	static SCSprite *createCover(const char *,CCSprite *,CCObject * =NULL, SEL_CallFuncN = NULL ,bool = true);
	static SCSprite *create(const char *,CCObject* = NULL ,SEL_CallFuncN =NULL);

	void setShowRect(CCRect rect);
	inline void setFileName(const char *str){fileName = str;};
	inline void setCardID(const char*str){cardID=str;};

inline const std::string getFileName(){return fileName ;};
	inline const std::string getCardID(){return cardID;};

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void onEnter();
	virtual void onExit();

	void visit();
};

