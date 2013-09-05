#include "SCSprite.h"


SCSprite::SCSprite(void)
	:callback(NULL)
	,m_pSelectorTarget(NULL)

{
	m_pCallFuncN = 0;
}


SCSprite::~SCSprite(void)
{
}

SCSprite *SCSprite::create(const char *file,CCObject *pTarget,SEL_CallFuncN pSelector)
{
	SCSprite *coverSprite = new SCSprite();
	if (coverSprite && coverSprite->initWithFile(file,pTarget,pSelector))
	{
		coverSprite->autorelease();
		return coverSprite;
	}
	CC_SAFE_DELETE(coverSprite);
	return NULL;

}

SCSprite *SCSprite::createCover(const char *file,CCSprite *cover,CCObject *pTarget,SEL_CallFuncN pSelector,bool bind)
{
	    SCSprite *coverSprite = new SCSprite();
	if (coverSprite &&coverSprite->initWithFile(file,pTarget,pSelector))
	{
		if (bind)
		{
			coverSprite->setAnchorPoint(ccp(0,0));
			coverSprite->setTag(0);
			cover->addChild(coverSprite);
			coverSprite->ignoreAnchorPointForPosition(true);
		}else
		{
			coverSprite->setAnchorPoint(ccp(0,0));
			coverSprite->ignoreAnchorPointForPosition(true);
			coverSprite->setPosition(cover->getPosition());

		}
	
		coverSprite->autorelease();
		return coverSprite;
	}
	CC_SAFE_DELETE(coverSprite);
	return NULL;

}

bool SCSprite::initWithFile(const char *file,void(*callback)(int))
{
	if (callback)
	{
		canTouch = true;
		this->callback = callback;
	}
	if (file)
	{
		CCSprite::initWithFile(file);
		return true;
	}
	return false;
}

bool SCSprite::initWithFile(const char *file,CCObject *pTarget,SEL_CallFuncN pSelector)
{
	if (pTarget)
	{
		canTouch = true;
		m_pSelectorTarget = pTarget;
		m_pCallFuncN=pSelector;
	}
	if (file)
	{
		CCSprite::initWithFile(file);
		return true;
	}
	return false;
}
bool SCSprite::initWithTexture(CCTexture2D *pTexture, const cocos2d::CCRect& tRect, CCObject* pTarget, SEL_CallFuncN pSelector)
{
	if (pTarget)
	{
		canTouch = true;
		m_pSelectorTarget=pTarget;
		m_pCallFuncN = pSelector;
	}
	return CCSprite::initWithTexture(pTexture,tRect);
}
bool SCSprite::containsTouchLocation(cocos2d::CCTouch *touch)
{
	CCPoint touchLocation = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
	CCPoint touchPoint = convertToNodeSpace(touchLocation);
	CCSize size = CCSizeZero;
	if (rect.size.width !=0 && rect.size.height !=0)
	{
		return rect.containsPoint(touchPoint);
	}else{
		return CCRectMake(0,0,getTextureRect().size.width,getTextureRect().size.height).containsPoint(touchPoint);
	}
}

void SCSprite::onEnter()
{
	if (canTouch)
	{
		CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);

	}
		CCSprite::onEnter();
}

void SCSprite::onExit()
{
	if (canTouch)
	{
		CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	}
	CCSprite::onExit();

}

bool SCSprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	if (!m_pCallFuncN)
	{
		return false;
	}
	return containsTouchLocation(touch);
}

void SCSprite::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

}

void SCSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	if (callback)
	{
		(*callback)(getTag());
	}else if (m_pCallFuncN && m_pSelectorTarget)
	{
		(m_pSelectorTarget->*m_pCallFuncN)((CCNode *)this);
	}

}

void SCSprite::setShowRect(CCRect rect)
{
	this->rect = rect;
	this->cocos2d::CCNode::setPosition(-rect.origin.x,-rect.origin.y);
}

void SCSprite::visit()
{
	if (rect.size.width == 0 || rect.size.height ==0)
	{
		CCSprite::visit();
		return;
	}
	glEnable(GL_SCISSOR_TEST);
	CCPoint p = this->getParent()->convertToWorldSpace(this->getPosition());
	CCSize sz =rect.size;

	CCRect rc = CCRectMake(p.x,p.y,sz.width,sz.height);
	CCRect portRect = CCEGLView::sharedOpenGLView()->getViewPortRect();

	glScissor(rc.origin.x * CCEGLView::sharedOpenGLView()->getScaleX() + portRect.origin.x + rect.origin.x  *
		CCEGLView::sharedOpenGLView()->getScaleX(),
		rc.origin.y * CCEGLView::sharedOpenGLView()->getScaleY() + portRect.origin.y + rect.origin.y  *
		CCEGLView::sharedOpenGLView()->getScaleY(),
		rc.size.width * CCEGLView::sharedOpenGLView()->getScaleX(),
		rc.size.height * CCEGLView::sharedOpenGLView()->getScaleY());

	CCSprite::visit() ;

	glDisable(GL_SCISSOR_TEST);


}
