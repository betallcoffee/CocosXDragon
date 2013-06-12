//
//  Bomb.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#include "Bomb.h"
#include "Dragon.h"

using namespace cocos2d;
using namespace cocos2d::extension;

bool Bomb::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !GameObject::init() )
    {
        return false;
    }

    return true;
}

void Bomb::update()
{
    
}

void Bomb::handleCollisionWith(GameObject *gameObject)
{
    if (dynamic_cast<Dragon*>(gameObject)) {
        // Collided with the dragon, remove object and add an explosion instead.
        this->setIsScheduledForRemove(true);
        
        CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
        CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
        CCNode* pExplosion = ccbReader->readNodeGraphFromFile("Explosion.ccbi");
        pExplosion->setPosition(this->getPosition());
        this->getParent()->addChild(pExplosion);
        ccbReader->release();
    }
}

float Bomb::getRadius()
{
    return 15;
}

