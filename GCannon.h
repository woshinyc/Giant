//
//  GCannon.h
//  Giant
//
//  Created by Mac on 13-9-5.
//
//

#ifndef __Giant__GCannon__
#define __Giant__GCannon__

#include <iostream>
#include "cocos2d.h"
#include "DBaseSprite.h"
#include "GCannonInfo.h"
USING_NS_CC;
class GCannon:public DBaseSprite//,public cocos2d::CCTargetedTouchDelegate
{
private:
    CCNode *_beHold;                    //炮所在的层
    CCSprite *cannonNumSp;              //炮号码精灵
    int cannonNum;                      //炮号
    static  GCannon* createGCannon();  
    CCSpriteBatchNode *baNode;          //cannon纹理batchNode
    bool canFire;                       //能否射击
    float interval;                     //时间间隔
    CannonInfo cannonInfo;
   inline void openFire(){canFire =true;}
    
    
public:
    static GCannon *shared(CCNode *beHold);
    static GCannon *shared();
    
    void addLevel();                  //加炮的等级
    void subLevel();                  //减炮的等级
    void fire();
//    
//    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
//    virtual void ccTouchMove(CCTouch *touch , CCEvent *event);
//    virtual void ccTouchEnded(CCTouch *touch,CCEvent *event);

    virtual void onEnter();
    virtual void onExit();



};
#endif /* defined(__Giant__GCannon__) */
