//
//  Level.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#include "Level.h"
#include "GameObject.h"
#include "Dragon.h"

#define kCJScrollFilterFactor 0.1
#define kCJDragonTargetOffset 80

using namespace cocos2d;
using namespace cocos2d::extension;

bool Level::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    return true;
}

void Level::onEnter()
{
    CCLayer::onEnter();
    CCLayer::scheduleUpdate();
}

void Level::onExit()
{
    CCLayer::unscheduleUpdate();
    CCLayer::onExit();
}

bool Level::onAssignCCBMemberVariable(CCObject * pTarget, CCString * pMemberVariableName, CCNode * pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "dragon", Dragon*, pmDragon);
    return false;
}

void Level::update(float delta)
{
    // Iterate through all objects in the level layer.
    CCArray* children = this->getChildren();
    CCObject* child;
    CCARRAY_FOREACH(children, child) {
        // Check if the child is a game object.
        if (GameObject* gameObject = dynamic_cast<GameObject*>(child)) {
            // Update game object.
            gameObject->update();
            if (gameObject != pmDragon) {
                if (ccpDistance(gameObject->getPosition(), pmDragon->getPosition()) <
                    gameObject->getRadius() + pmDragon->getRadius()) {
                    // Notify the gameobject that they have collied.
                    gameObject->handleCollisionWith(pmDragon);
                    pmDragon->handleCollisionWith(gameObject);
                }
            }
        }
    }
    
    // Check for objects to remove.
    CCARRAY_FOREACH(children, child) {
        if (GameObject* gameObject = dynamic_cast<GameObject*>(child)) {
            if (gameObject->getIsScheduledForRemove()) {
                removeChild(gameObject, true);
            }
        }
    }
    
    // Adjust the position of the layer so dragon is visible.
    float yTarget = kCJDragonTargetOffset - pmDragon->getPositionY();
    CCPoint oldLayerPosition = getPosition();
    setPosition(oldLayerPosition.x, yTarget * kCJScrollFilterFactor + oldLayerPosition.y * (1.0f - kCJScrollFilterFactor));
}


