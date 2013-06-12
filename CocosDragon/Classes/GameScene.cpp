//
//  GameScene.cpp
//  CocosDragon
//
//  Created by liangliang on 13-6-1.
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Dragon.h"
#include "Level.h"
#include "Bomb.h"
#include "Coin.h"
#include "Explosion.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;

GameScene* GameScene::mpSharedScene = new GameScene();

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

GameScene* GameScene::sharedScene()
{
    return mpSharedScene;
}

bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    return true;
}

#pragma mark -
#pragma mark CCBSelectorResolver

SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(CCObject *pTarget, CCString *pSelectorName)
{
    return NULL;
}

SEL_CCControlHandler GameScene::onResolveCCBCCControlSelector(CCObject *pTarget, CCString *pSelectorName)
{
    return NULL;
}

#pragma mark -
#pragma mark CCNodeLoaderListener

void GameScene::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    mScore = 0;
    // Load the level
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("Dragon", DragonLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Level", LevelLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Bomb", BombLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Coin", CoinLoader::loader());
    ccNodeLoaderLibrary->registerCCNodeLoader("Explosion", ExplosionLoader::loader());
    CCBReader *ccbReader = new CCBReader(ccNodeLoaderLibrary);
    mpLevel = ccbReader->readNodeGraphFromFile("Level.ccbi");
    this->addChild(mpLevel);
    ccbReader->release();
}

#pragma mark -
#pragma mark getter and setter

void GameScene::setScore(int score)
{
    mScore = score;
    CCString *sScore = CCString::createWithFormat("%d", mScore);
//    mpScoreLabel->setString(sScore->getCString());
}

#pragma mark -
#pragma mark handler*

void GameScene::handleGameOver()
{
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    CCBReader *ccBReader = new CCBReader(ccNodeLoaderLibrary);
    CCScene *pMainScene = ccBReader->createSceneWithNodeGraphFromFile("MainMenuScene.ccbi");
    CCDirector::sharedDirector()->replaceScene(pMainScene);
    ccBReader->release();
}

void GameScene::handleLevelComplete()
{
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    CCBReader *ccBReader = new CCBReader(ccNodeLoaderLibrary);
    CCScene *pMainScene = ccBReader->createSceneWithNodeGraphFromFile("MainMenuScene.ccbi");
    CCDirector::sharedDirector()->replaceScene(pMainScene);
    ccBReader->release();
}



