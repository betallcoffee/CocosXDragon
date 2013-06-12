//
//  MainMenuScene.h
//  CocosDragon
//
//  Created by liangliang on 13-5-29.
//
//

#ifndef __CocosDragon__MainMenuScene__
#define __CocosDragon__MainMenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class MainMenuScene :
  public cocos2d::CCLayer,
  public cocos2d::extension::CCBSelectorResolver
{
    
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, cocos2d::CCString *pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, cocos2d::CCString *pSelectorName);
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(MainMenuScene);
    
    void pressedPlay(void *sender);
};

class MainMenuLoader : public cocos2d::extension::CCLayerLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainMenuLoader, loader);

protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainMenuScene);
    
};
#endif /* defined(__CocosDragon__MainMenuScene__) */
