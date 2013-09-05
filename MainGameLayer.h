//
//  MainGameLayer.h
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#ifndef __Giant__MainGameLayer__
#define __Giant__MainGameLayer__

#include <iostream>
#include "DBaseLayer.h"
class MainGameLayer:public DBaseLayer
{
    
private:
    void createCannon();
public:
    static cocos2d::CCScene* scene();
    virtual bool init();
    CREATE_FUNC(MainGameLayer);
    
virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
virtual void ccTouchMoved(CCTouch *touch , CCEvent *event);
virtual void ccTouchEnded(CCTouch *touch,CCEvent *event);

virtual void onEnter();
virtual void onExit();

};

#endif /* defined(__Giant__MainGameLayer__) */
