//
//  Coin.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#include "Coin.h"
#include "GameScene.h"
#include "Dragon.h"

using namespace cocos2d;
using namespace cocos2d::extension;

bool Coin::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !GameObject::init() )
    {
        return false;
    }

    return true;
}

void Coin::update()
{
    
}

void Coin::handleCollisionWith(GameObject *gameObject)
{
    if (dynamic_cast<Dragon*>(gameObject)) {
        if (mIsEndCoin) {
            // Level is complete.
            GameScene::sharedScene()->handleLevelComplete();
        }
    }
}

float Coin::getRadius()
{
    return 15;
}

void CoinLoader::onHandlePropTypeCheck(CCNode *pNode, CCNode *pParent, CCString *pPropertyName, bool pCheck, CCBReader *pCCBReader)
{
    if(pPropertyName->compare("isEndCoin") == 0) {
        dynamic_cast<Coin*>(pNode)->setIsEndCoin(pCheck);
    } else {
        CCNodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }

}
