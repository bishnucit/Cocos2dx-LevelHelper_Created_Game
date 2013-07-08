#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("TileMap", "Arial", TITLE_FONT_SIZE);

    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
   tileMap = CCTMXTiledMap::create("C:/Users/bisprasad/Desktop/TileMap1.tmx");
    this->addChild(tileMap);
    CCTMXLayer *background = tileMap->layerNamed("Background");
	CCTMXObjectGroup *objectGroup = tileMap->objectGroupNamed("Objects");
	/*CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");
	
	CCString *pX = (CCString*)spawnPoint->objectForKey("x");
	CCString *pY = (CCString*)spawnPoint->objectForKey("y");
 */

	cocos2d::CCDictionary *spawnPoint = objectGroup->objectNamed("SpawnPoint");
	CCAssert(spawnPoint != NULL, "SpawnPoint object not found");
	CCString *pX = (CCString*)spawnPoint->objectForKey("x");
	CCString *pY = (CCString*)spawnPoint->objectForKey("y");
	 
	 int x = pX->intValue();
	 int y = pY->intValue();
	 this->addChild(tileMap );
	CCSprite  *player = CCSprite::create("C:/Users/bisprasad/Desktop/Player.png");
	 
	 player->setPosition(ccp(x,y/3.74));
	 
	this->setViewPointCenter(player->getPosition());

	
	

    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::setViewPointCenter(CCPoint position)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int x = MAX(position.x,winSize.width/2);
	int y = MAX(position.y,winSize.height/2);
	x = MIN(x,(tileMap->getMapSize().width * tileMap->getTileSize().width)-winSize.width/2);
	y = MIN(y,(tileMap->getMapSize().height * tileMap->getTileSize().height)-winSize.height/2);
	CCPoint actualPosition = ccp(x,y);
	CCPoint centerofView = ccp(winSize.width/2, winSize.height/2); 
	centerofView = ccpSub(centerofView, actualPosition);
	this->setPosition(centerofView);


}