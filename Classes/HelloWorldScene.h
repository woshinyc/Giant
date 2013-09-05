#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
typedef int (*FP_CALC)(int, int);
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
   // int diva(int a, int b);
   // FP_CALC calc_func(char op);
    void aaa(CCNode *node);
    int n;
    void  httpResponseCallback(CCNode *node,void *data);

};

#endif // __HELLOWORLD_SCENE_H__
