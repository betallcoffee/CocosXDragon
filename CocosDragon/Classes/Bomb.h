//
//  Bomb.h
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#ifndef __CocosDragon__Bomb__
#define __CocosDragon__Bomb__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameObject.h"

class Bomb : public GameObject
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual void update();
    virtual void handleCollisionWith(GameObject *gameObject);
    
    // getter and setter
    virtual float getRadius();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Bomb);
    
};

class BombLoader : public cocos2d::extension::CCNodeLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BombLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Bomb);
};

#endif /* defined(__CocosDragon__Bomb__) */
