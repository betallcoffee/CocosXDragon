//
//  Explosion.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#include "Explosion.h"

using namespace cocos2d;
using namespace cocos2d::extension;

bool Explosion::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !GameObject::init() )
    {
        return false;
    }

    return true;
}

void Explosion::update()
{
    
}

void Explosion::handleCollisionWith(GameObject *gameObject)
{
    
}

void Explosion::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCBAnimationManager *ccbAnimationManager = dynamic_cast<CCBAnimationManager*>(getUserObject());
    if (ccbAnimationManager) {
        ccbAnimationManager->setDelegate(this);
    }
    
}

void Explosion::completedAnimationSequenceNamed(const char *name)
{
    mIsScheduledForRemove = true;
}
