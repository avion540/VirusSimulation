#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
private:
    PhysicsWorld *sceneWorld;
    void SetPhysicsWorld(PhysicsWorld *world) { sceneWorld = world; };
    
    // Collision detection
    bool onContactBegin(PhysicsContact &contact);
    
    TMXTiledMap *_tileMap;      // Keep track of map
    TMXLayer *_background;      // Keep track of background layer in map
    Sprite *_player;            // Player sprite
    
public:
    void setViewPointCenter(cocos2d::Point position);
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void addSprite(float dt);
    
    //void update(float dt);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
