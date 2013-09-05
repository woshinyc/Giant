//
//  DBaseLayer.h
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#ifndef __Giant__DBaseLayer__
#define __Giant__DBaseLayer__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
class DBaseLayer :public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(DBaseLayer);

};
#endif /* defined(__Giant__DBaseLayer__) */
