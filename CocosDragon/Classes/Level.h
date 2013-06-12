//
//  Level.h
//  CocosDragon
//
//  Created by liangliang on 13-6-3.
//
//

#ifndef __CocosDragon__Level__
#define __CocosDragon__Level__

#include "cocos2d.h"
#include "cocos-ext.h"

class Dragon;

class Level :
  public cocos2d::CCLayer,
  public cocos2d::extension::CCBMemberVariableAssigner
{
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, cocos2d::CCString * pMemberVariableName, CCNode * pNode);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Level);
    
    void update(float delta);
    
private:
    Dragon* pmDragon;
    
};

class LevelLoader : public cocos2d::extension::CCNodeLoader {
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level);
};

#endif /* defined(__CocosDragon__Level__) */
