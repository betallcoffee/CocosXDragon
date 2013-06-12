//
//  MainMenuScene.cpp
//  CocosDragon
//
//  Created by liangliang on 13-5-29.
//
//

#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::extension;

CCScene* MainMenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenuScene *layer = MainMenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    return true;
}

SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(CCObject *pTarget, CCString *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPlay", MainMenuScene::pressedPlay);
    return NULL;
}

SEL_CCControlHandler MainMenuScene::onResolveCCBCCControlSelector(CCObject *pTarget, CCString *pSelectorName)
{
    return NULL;
}

void MainMenuScene::pressedPlay(void *sender)
{
    // Load the game scene
    CCNodeLoaderLibrary *ccNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader("GameScene", GameLoader::loader());
    CCBReader *ccBReader = new CCBReader(ccNodeLoaderLibrary);
    CCScene *pScene = ccBReader->createSceneWithNodeGraphFromFile("GameScene.ccbi");
    
    // Go to the game scene
    CCDirector::sharedDirector()->replaceScene(pScene);
    ccBReader->release();
}


