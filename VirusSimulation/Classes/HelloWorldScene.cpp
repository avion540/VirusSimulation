#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

USING_NS_CC;

// Random function. Returns random float from min to max
static inline float rand_range(float min_num, float max_num) {
    return min_num+(CCRANDOM_0_1()*(max_num-min_num));
}


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}



// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1
    if ( !Layer::init() ) {
        return false;
    }
    // Using current time as seed for random generator
    srand(time(0));

    auto background = DrawNode::create();
    this->addChild(background);
    
    // Create physics boundary
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // Set-up random spawn locations for sprites
    float randX = rand_range(0, visibleSize.width);
    float randY = rand_range(0, visibleSize.height);
    
    // Set physics boundary
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0,1,0) );
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    
    this->addChild(edgeNode);
    
    // Physics
    auto physicsBody = PhysicsBody::createBox(Size(20.0f, 20.0f), PhysicsMaterial(0, .9, 0));
    physicsBody->setCollisionBitmask(1);
    physicsBody->setContactTestBitmask(true);
    physicsBody->setDynamic(false);
    
    // Create a sprite
    auto sprite = Sprite::create("sick_face.png");
    Size size = Director::getInstance()->getWinSize();      // Get size of window to set size of sprite
    sprite->setPosition(size.width/2, size.height/2);
    addChild(sprite);
    
    // Apply physicsBody to the sprite
    sprite->setPhysicsBody(physicsBody);
    
    // Collision detection
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    // Add five dynamic body
    for (int i = 0; i < 5; ++i)
    {
        physicsBody = PhysicsBody::createBox(Size(20.0f, 20.0f), PhysicsMaterial(0, 1, 0));
        physicsBody->setCollisionBitmask(2);
        physicsBody->setContactTestBitmask(true);
        // Set the body so it isn't affected by the physics world's gravitational force
        physicsBody->setGravityEnable(false);
        
        // Set initial velocity of physicsBody
        physicsBody->setVelocity(Vec2(cocos2d::random(-300,300),
                                      cocos2d::random(-300,300)));
        //physicsBody->setTag(DRAG_BODYS_TAG);
        
        // Generate happy face sprite
        auto spriteHappy = Sprite::create("happy_face.png");
        spriteHappy->setPosition(Vec2(visibleSize.width/3 + rand() % 200, visibleSize.height/3 + rand() % 200));
        spriteHappy->setPhysicsBody(physicsBody);
        
        addChild(spriteHappy);
    }
    
    
    //sprite->getPhysicsBody()->applyForce(Vec2(100, 300));
    
    // Background Music
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->preloadBackgroundMusic("TownTheme.mp3");
    audio->playBackgroundMusic("TownTheme.mp3");
    

    
    return true;
}

bool HelloWorld::onContactBegin(cocos2d::PhysicsContact &contact) {
    PhysicsBody *a = contact.getShapeA()->getBody();
    PhysicsBody *b = contact.getShapeB()->getBody();
    
    // Check if the bodies have collided
    if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) || 2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()) {
        CCLOG("COLLISION HAS OCCURED");
        //spriteHappy->setTexture("sick_face.png");
    }
    return true;
}

void HelloWorld::addSprite(float dt) {

}
