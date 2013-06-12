//
//  Dragon.h
//  CocosDragon
//
//  Created by liangliang on 13-6-5.
//
//

#ifndef __CocosDragon__Dragon__
#define __CocosDragon__Dragon__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameObject.h"

class Dragon : public GameObject
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    virtual void update();
    virtual void handleCollisionWith(GameObject *gameObject);
    
    // getter and setter
    virtual float getRadius();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Dragon);
    
    // members
    CC_SYNTHESIZE(float, mYSpeed, ySpeed)
    CC_SYNTHESIZE(float, mXTarget, xTarget)
};

class DragonLoader : public cocos2d::extension::CCNodeLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(DragonLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Dragon);
};

#endif /* defined(__CocosDragon__Dragon__) */
