//
//  Coin.h
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#ifndef __CocosDragon__Coin__
#define __CocosDragon__Coin__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameObject.h"

class Coin :
  public GameObject
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual void update();
    virtual void handleCollisionWith(GameObject *gameObject);
    
    // getter and setter
    virtual float getRadius();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Coin);
    
    // members
    CC_SYNTHESIZE(bool, mIsEndCoin, IsEndCoin);
};

class CoinLoader : public cocos2d::extension::CCNodeLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CoinLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Coin);
    
    virtual void onHandlePropTypeCheck(cocos2d::CCNode * pNode, cocos2d::CCNode * pParent, cocos2d::CCString * pPropertyName, bool pCheck, cocos2d::extension::CCBReader * pCCBReader);
};

#endif /* defined(__CocosDragon__Coin__) */
