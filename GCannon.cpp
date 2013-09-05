//
//  GCannon.cpp
//  Giant
//
//  Created by Mac on 13-9-5.
//
//

#include "GCannon.h"
#include "GTool.h"
#include "DDefine.h"
using namespace std;

static GCannon *s_instance = NULL;
GCannon *GCannon::shared(CCNode *beHold)
{
    if (!s_instance) {
        s_instance =  GCannon::createGCannon();
        s_instance->cannonNum=1;
    }
    if (s_instance->_beHold) {
        s_instance->_beHold->removeChild(s_instance->baNode);
    }
    beHold->addChild(s_instance->baNode);
    s_instance->_beHold=beHold;
    return s_instance;

}
GCannon * GCannon::shared()
{
    if (s_instance) {
        return s_instance;
    }
    return NULL;
}

GCannon*  GCannon::createGCannon()
{
    GCannon *cannon =new GCannon();
  CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("cannon.plist");
    CCSpriteBatchNode *batchNode=CCSpriteBatchNode::create("cannon.png");
    cannon->baNode=batchNode;
    cannon->cannonNum=1;
    
    cannon->initWithSpriteFrameName("Barrel.png");
    // 
    cannon->cannonNumSp=CCSprite::createWithSpriteFrameName("Cannon01.png");
    cannon->cannonNumSp->setPosition(ccpsprite(0.5, 0.5, cannon));
    //
    cannon->addChild(cannon->cannonNumSp);
    return cannon;
}

void GCannon::addLevel()
{
    if (cannonNum==MAX_CANNON_LEVEL) {
        return;
    }
    ++cannonNum;
    char name[128];
    sprintf(name,"Cannon%2d.png",cannonNum);

    cannonNumSp->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}
void GCannon::subLevel()
{
    if (cannonNum==MIN_CANNON_LEVEL) {
        return;
    }
    --cannonNum;
    char name[128];
    sprintf(name,"Cannon%2d.png",cannonNum);
    
    cannonNumSp->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}


void GCannon::fire()
{
    if (canFire) {
        canFire=false;
        CCDelayTime *d=CCDelayTime::create(2);
        CCCallFunc *c= CCCallFunc::create(this, callfunc_selector(GCannon::openFire));
        
        CCSequence * se=CCSequence::create(d,c,NULL);
        runAction(se);
    }
    return;
}


#pragma mark--加入触摸监测
void GCannon::onEnter()
{
    
    //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCSprite::onEnter();
}

void GCannon::onExit()
{
   // CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

//#pragma mark  touchDelegate
//
//bool GCannon::ccTouchBegan(CCTouch* touch, CCEvent* event)
//{
//    
//    CCPoint touchLocation = touch->getLocation();
//   // printf("x=%f,y=%f",touchLocation.x,touchLocation.y);
//    return true;
//}
//
//void GCannon::ccTouchMove(CCTouch* touch, CCEvent* event)
//{
//    CCLog("ll");
//}
//
//void GCannon::ccTouchEnded(CCTouch* touch, CCEvent* event)
//{
//    
//    
//}
