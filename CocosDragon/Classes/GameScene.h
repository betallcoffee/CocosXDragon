//
//  GameScene.h
//  CocosDragon
//
//  Created by liangliang on 13-6-1.
//
//

#ifndef __CocosDragon__GameScene__
#define __CocosDragon__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"

class GameScene :
  public cocos2d::CCLayer,
  public cocos2d::extension::CCBSelectorResolver,
  public cocos2d::extension::CCNodeLoaderListener
{
public:
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    // Singleton instance.
    static GameScene* sharedScene();
    
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, cocos2d::CCString *pSelectorName);
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, cocos2d::CCString *pSelectorName);
    virtual void onNodeLoaded(cocos2d::CCNode* pNode, cocos2d::extension::CCNodeLoader* pNodeLoader);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScene);
    
    // setter and getter
    void setScore(int score);
    int getScore() { return mScore; };
    
    //
    void handleGameOver();
    void handleLevelComplete();
    
    // memebers;
private:
    static GameScene* mpSharedScene;
    cocos2d::CCLayer* mpLevelLayer;
    cocos2d::CCLabelTTF* mpScoreLabel;
    cocos2d::CCNode* mpLevel;
    int mScore;
    
};

class GameLoader : public cocos2d::extension::CCLayerLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameScene);
};

#endif /* defined(__CocosDragon__GameScene__) */
