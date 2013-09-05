//
//  ResourcesHelper.h
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#ifndef __Giant__ResourcesHelper__
#define __Giant__ResourcesHelper__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class ResourcesHelper
{
    
private:
    CCNode *_beHold;
    
public:
    static ResourcesHelper* shared(CCNode *beHold);
    
    
    void readResourcesWithLevel(int level);


};
#endif /* defined(__Giant__ResourcesHelper__) */
