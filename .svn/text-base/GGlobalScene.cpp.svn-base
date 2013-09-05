//
//  GGlobalScene.cpp
//  Giant
//
//  Created by Mac on 13-9-4.
//
//

#include "GGlobalScene.h"
#include "DDefine.h"

static GGlobalScene *s_instance = NULL;
GGlobalScene *GGlobalScene ::shared()
{
    if (!s_instance) {
           s_instance = GGlobalScene::create();
    }

    return s_instance;
}

bool GGlobalScene::init()
{
    bool ret = true;
    
    CCSize frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    CCSize gameSize = CCSizeMake(LOGIC_SCREEN_WIDTH, LOGIC_SCREEN_HEIGHT);
    
    float scaleX = (float) frameSize.width / gameSize.width;
    float scaleY = (float) frameSize.height / gameSize.height;
    
    // 定义 scale 变量
    float scale = 0.0f; // MAX(scaleX, scaleY);
    if (scaleX > scaleY) {
        // 如果是 X 方向偏大，那么 scaleX 需要除以一个放大系数，放大系数可以由枞方向获取，
        // 因为此时 FrameSize 和 LsSize 的上下边是重叠的
        scale = scaleX / (frameSize.height / (float) gameSize.height);
    } else {
        scale = scaleY / (frameSize.width / (float) gameSize.width);
    }
    
    CCLog("x: %f; y: %f; scale: %f", scaleX, scaleY, scale);
    // 根据 LsSize 和屏幕宽高比动态设定 WinSize
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(gameSize.width * scale,
                                                           gameSize.height * scale, kResolutionNoBorder);
    this->setPositionX((int)((scale-1)*gameSize.width/2));
    this->setPositionY((int)((scale-1)*gameSize.height/2));
    
    return ret;

}


void GGlobalScene::addLayer(CCNode * layer, LayerTypeTag tag, bool hidePre)
{

    switch (tag) {
        case Layer_type_tag_logo:
            while (v_node_add.size()>0) {
                v_node_add.back()->unscheduleAllSelectors();
            }
            break;
        case Layer_type_tag_main:
            ;
            break;
        case layer_type_tag_loading:
            ;
            break;
            
        default:
            break;
    }


}