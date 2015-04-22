#include "NextScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* NextScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = NextScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

//void(*calcfunc[])(cocos2d::Ref* pSender) = { calcfunc1, calcfunc2, calcfunc3, calcfunc4, calcfunc5, calcfunc6, calcfunc7, calcfunc8, calcfunc9, calcfunc0 };

bool NextScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(NextScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("earth.png");
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	// 表示エリアを作成
	auto disp = LayerColor::create(Color4B::WHITE, 500, 50);
	disp->setPosition(Vec2(visibleSize.width*.2, visibleSize.height*.8));
	this->addChild(disp, 1);

	auto dispnum = Label::createWithTTF("0000000000", "fonts/arial.ttf", 36);
	dispnum->setColor(ccc3(0, 0, 0));
	dispnum->setPosition(Vec2(visibleSize.width*.5, visibleSize.height*.85));
	this->addChild(dispnum, 1);

	// 関数ポインタの登録はあっているが、関数ポインタをコールバックに登録はできないようだ
	NextScene nc;
	void (NextScene::*calcfunc[10])(cocos2d::Ref* pSender) = { &NextScene::calcfunc1, &NextScene::calcfunc2, &NextScene::calcfunc3, &NextScene::calcfunc4, &NextScene::calcfunc5,
															   &NextScene::calcfunc6, &NextScene::calcfunc7, &NextScene::calcfunc8, &NextScene::calcfunc9, &NextScene::calcfunc0};
	// 数字ボタンを作成
	for (int i = 1; i <= 10; i++)
	{
		//100*100にクロップ
		CCRect rectbef = CCRectMake(100 * (i - 1), 0, 100, 100);
		CCSprite* numsbef = CCSprite::create("numbuttonbef.png", rectbef);
		CCRect rectaft = CCRectMake(100 * (i - 1), 0, 100, 100);
		CCSprite* numsaft = CCSprite::create("numbuttonaft.png", rectaft);

		// 計算用関数ポインタをコールバックに登録したかった
		/*
		auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(nc.*calcfunc[i], this));
		//メニューの作成　pMenuの中にnumbuttonを入れる
		auto pMenu = Menu::create(numbutton, NULL);
		pMenu->setPosition(ccp(visibleSize.width*i*.25, visibleSize.height / 2));
		this->addChild(pMenu, 1);
		*/

		if (i == 1)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc1, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.7));
			this->addChild(pMenu, 1);
		}
		else if (i == 2)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc2, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.7));
			this->addChild(pMenu, 1);
		}
		else if (i == 3)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc3, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.7));
			this->addChild(pMenu, 1);
		}
		else if (i == 4)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc4, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 5)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc5, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 6)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc6, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 7)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc7, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.3));
			this->addChild(pMenu, 1);
		}
		else if (i == 8)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc8, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.3));
			this->addChild(pMenu, 1);
		}
		else if (i == 9)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc9, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 1)*.15 + 100, visibleSize.height*.3));
			this->addChild(pMenu, 1);
		}
		else if (i == 10)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc0, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*((i - 1) % 3 + 2)*.15 + 100, visibleSize.height*.1));
			this->addChild(pMenu, 1);
		}
	}

	return true;
}

void NextScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->replaceScene(HelloWorld::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void NextScene::calcfunc1(Ref* pSender)
{
	log("Tapp1");
}
void NextScene::calcfunc2(Ref* pSender)
{
	log("Tapp2");
}
void NextScene::calcfunc3(Ref* pSender)
{
	log("Tapp3");
}

void NextScene::calcfunc4(Ref* pSender)
{
	log("Tapp4");
}

void NextScene::calcfunc5(Ref* pSender)
{
	log("Tapp5");
}

void NextScene::calcfunc6(Ref* pSender)
{
	log("Tapp6");
}

void NextScene::calcfunc7(Ref* pSender)
{
	log("Tapp7");
}

void NextScene::calcfunc8(Ref* pSender)
{
	log("Tapp8");
}

void NextScene::calcfunc9(Ref* pSender)
{
	log("Tapp9");
}

void NextScene::calcfunc0(Ref* pSender)
{
	log("Tapp0");
}
