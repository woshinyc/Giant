//
//  GGlobalScene.h
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#ifndef __Giant__GGlobalScene__
#define __Giant__GGlobalScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;

typedef enum
{
    Layer_type_tag_logo = 0,
    Layer_type_tag_main,
    layer_type_tag_loading,
    layer_type_tag_choose


}LayerTypeTag;
class GGlobalScene : public cocos2d::CCScene
{
private:
    
    void addLayer(CCNode * layer, LayerTypeTag tag, bool hidePre);
    CREATE_FUNC(GGlobalScene);
    virtual bool init();
    
    std::vector<CCLayer *> v_node_add;
    std::vector<CCLayer *> v_node_sp;
    
public:
    static  GGlobalScene *shared();
    CCPoint getGlobalOffset();
    
    void replaceLayer(CCNode * layer);
    
    void pushLayer(CCNode * layer , bool hidePre = true);
    void popLayer();
    
    void removeLayer(LayerTypeTag tag);
    void removeMainLayer();

};
#endif /* defined(__Giant__GGlobalScene__) */
