//
//  DBaseSprite.h
//  Giant
//
//  Created by Mac on 13-9-5.
//
//

#ifndef __Giant__DBaseSprite__
#define __Giant__DBaseSprite__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class DBaseSprite:public CCSprite
{
private:
    int hp;
    int mp;
    
    
public:
    inline void setHp(int num){hp=num;}
    inline void setMp(int num){mp=num;}
    inline int getHp(){return hp;}
    inline int getMp(){return mp;}
  
    
};
#endif /* defined(__Giant__DBaseSprite__) */
