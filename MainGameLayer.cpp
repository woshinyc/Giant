//
//  MainGameLayer.cpp
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#include "MainGameLayer.h"
#include "ResourcesHelper.h"
#include "GTool.h"
#include "GCannon.h"

CCScene* MainGameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainGameLayer *layer = MainGameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainGameLayer::init()
{
    if (DBaseLayer::init()) {
        
        
//        ResourcesHelper::shared(this)->readResourcesWithLevel(1);
       CCSprite *bg=CCSprite::create("bg.jpg");
        bg->setPosition(ccps(0.5, 0.5));
        addChild(bg);
        createCannon();
        return true;
    }
    return false;
}

#pragma mark---构建大炮
void MainGameLayer::createCannon()
{
    GCannon *canno=GCannon::shared(this);
    canno->setPosition(ccps(0.5, 0.1));
    this->addChild(canno);



}

#pragma mark--加入触摸监测
void MainGameLayer::onEnter()
{
    setTouchEnabled(true);
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void MainGameLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

#pragma mark  touchDelegate

bool MainGameLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
   
 CCPoint touchLocation = touch->getLocation();

GCannon::shared()->setRotation(-(CC_RADIANS_TO_DEGREES(radianAandOrigin(touchLocation, GCannon::shared()->getPosition()))-90));
    
    return true;
}

void MainGameLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    CCPoint touchLocation = touch->getLocation();
    GCannon::shared()->setRotation(-(CC_RADIANS_TO_DEGREES(radianAandOrigin(touchLocation, GCannon::shared()->getPosition()))-90));
}

void MainGameLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{

    
}

