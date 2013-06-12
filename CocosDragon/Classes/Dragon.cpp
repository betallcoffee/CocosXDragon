//
//  Dragon.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-5.
//
//

#include "Dragon.h"
#include "GameScene.h"
#include "Coin.h"
#include "Bomb.h"

#define kCJStartSpeed 8
#define kCJCoinSpeed 8
#define kCJStartTarget 160
#define kCJTargetFilterFactor 0.05
#define kCJSlowDownFactor 0.995
#define kCJGravitySpeed 0.1
#define kCJGameOverSpeed -10
#define kCJDeltaToRotationFactor 5

using namespace cocos2d;
using namespace cocos2d::extension;

bool Dragon::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !GameObject::init() )
    {
        return false;
    }
    mXTarget = kCJStartTarget;
    mYSpeed = kCJStartSpeed;
    return true;
}

#pragma mark -
#pragma mark getter and setter

float Dragon::getRadius()
{
    return 25;
}

#pragma mark - 
#pragma mark update

void Dragon::update()
{
    // Calculate new position.
    const CCPoint& oldPosition = this->getPosition();
    float xNew = mXTarget * kCJTargetFilterFactor + oldPosition.x * (1 - kCJTargetFilterFactor);
    float yNew = oldPosition.y + mYSpeed;
    this->setPosition(xNew, yNew);
    
    // Update the vertical speed.
    mYSpeed = (mYSpeed - kCJGravitySpeed) * kCJSlowDownFactor;
    
    // Tilt the dragon depending on horizontal speed.
    float xDelta = xNew - oldPosition.x;
    this->setRotation(xDelta * kCJDeltaToRotationFactor);
    
    // Check for game over
    if (mYSpeed < kCJGameOverSpeed) {
        GameScene::sharedScene()->handleGameOver();
    }
    
}

#pragma mark -
#pragma mark handle*

void Dragon::handleCollisionWith(GameObject *gameObject)
{
    if (dynamic_cast<Coin*>(gameObject)) {
        // Took a coin.
        mYSpeed = kCJCoinSpeed;
        int socre = GameScene::sharedScene()->getScore();
        GameScene::sharedScene()->setScore(++socre);
        
    } else if (dynamic_cast<Bomb*>(gameObject)) {
        // Hit a bomb
        if (mYSpeed > 0) {
            mYSpeed = 0;
        }
        
        CCBAnimationManager *ccbAnimationManager = dynamic_cast<CCBAnimationManager*>(getUserObject());
        if (ccbAnimationManager) {
            ccbAnimationManager->runAnimations("Hit");
        }
    }
}


