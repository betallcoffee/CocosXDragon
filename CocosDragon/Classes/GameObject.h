//
//  GameObject.h
//  CocosDragon
//
//  Created by liangliang on 13-6-5.
//
//

#ifndef __CocosDragon__GameObject__
#define __CocosDragon__GameObject__

#include "cocos2d.h"
#include "cocos-ext.h"

class GameObject : public cocos2d::CCNode
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    virtual void update() = 0;
    virtual void handleCollisionWith(GameObject *gameObject) = 0;
    
    // memebers
    CC_SYNTHESIZE(bool, mIsScheduledForRemove, IsScheduledForRemove);
    CC_SYNTHESIZE(float, mRadius, Radius);
    
};

#endif /* defined(__CocosDragon__GameObject__) */
