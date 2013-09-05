//
//  ResourcesHelper.cpp
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#include "ResourcesHelper.h"


static ResourcesHelper * s_Resources = NULL;

ResourcesHelper *ResourcesHelper ::shared(CCNode *beHold)
{
    if (!s_Resources) {
        s_Resources = new ResourcesHelper();
        
    }
s_Resources->_beHold=beHold;
    return s_Resources;
}

void ResourcesHelper ::readResourcesWithLevel(int level)
{
    CCSpriteBatchNode *batchNode;
    switch (level) {
        case 1:
            
//            batchNode=CCSpriteBatchNode::create("Cannon.png");
//            _beHold->addChild(batchNode);
            break;
            
            
        default:
            break;
    }


}

