#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "tilemap_parallax_nodes\CCTMXTiledMap.h"
#include "tilemap_parallax_nodes\CCTMXLayer.h"
#include "tilemap_parallax_nodes\CCTMXObjectGroup.h"
#include "tilemap_parallax_nodes\CCParallaxNode.h"
#include "tilemap_parallax_nodes\CCTileMapAtlas.h"
#include "tilemap_parallax_nodes\CCTMXXMLParser.h"


class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	 
	cocos2d::CCTMXTiledMap *tileMap;
	cocos2d::CCTMXLayer *background;
	void  setViewPointCenter(cocos2d::CCPoint position);
};

enum
{tag = 1};

#endif // __HELLOWORLD_SCENE_H__
