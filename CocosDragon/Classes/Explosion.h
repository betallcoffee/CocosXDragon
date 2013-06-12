//
//  Explosion.h
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#ifndef __CocosDragon__Explosion__
#define __CocosDragon__Explosion__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameObject.h"

class Explosion :
  public GameObject,
  public cocos2d::extension::CCNodeLoaderListener,
  public cocos2d::extension::CCBAnimationManagerDelegate
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual void update();
    virtual void handleCollisionWith(GameObject *gameObject);
    virtual void onNodeLoaded(cocos2d::CCNode* pNode, cocos2d::extension::CCNodeLoader* pNodeLoader);
    virtual void completedAnimationSequenceNamed(const char *name);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Explosion);
    
};

class ExplosionLoader : public cocos2d::extension::CCNodeLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ExplosionLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Explosion);
};

#endif /* defined(__CocosDragon__Explosion__) */
