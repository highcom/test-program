#include <sstream>
#include "NextScene.h"
#include "HelloWorldScene.h"
#include "CalcResult.h"

using namespace std;

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

	// �\���G���A���쐬
	auto disp = LayerColor::create(Color4B::WHITE, 500, 50);
	disp->setPosition(Vec2(visibleSize.width*.2, visibleSize.height*.9));
	this->addChild(disp, 1);

	cr.resultstr = "0";
	cr.resultnum = 0;
	cr.opera = NULL;
	cr.opera_flg = false;
	dispnum = Label::createWithTTF(cr.resultstr, "fonts/arial.ttf", 36);
	//auto dispnum = Label::createWithTTF(cr.resultnum, "fonts/arial.ttf", 36);
	dispnum->setColor(ccc3(0, 0, 0));
	dispnum->setPosition(Vec2(visibleSize.width*.5, visibleSize.height*.95));
	this->addChild(dispnum, 1);

	// �֐��|�C���^�̓o�^�͂����Ă��邪�A�֐��|�C���^���R�[���o�b�N�ɓo�^�͂ł��Ȃ��悤��
	NextScene nc;
	void (NextScene::*calcfunc[10])(cocos2d::Ref* pSender) = { &NextScene::calcfunc1, &NextScene::calcfunc2, &NextScene::calcfunc3, &NextScene::calcfunc4, &NextScene::calcfunc5,
															   &NextScene::calcfunc6, &NextScene::calcfunc7, &NextScene::calcfunc8, &NextScene::calcfunc9, &NextScene::calcfunc0};
	// �����{�^�����쐬
	for (int i = 1; i <= 10; i++)
	{
		//100*100�ɃN���b�v
		CCRect rectbef = CCRectMake(100 * (i - 1), 0, 100, 100);
		CCSprite* numsbef = CCSprite::create("numbuttonbef.png", rectbef);
		CCRect rectaft = CCRectMake(100 * (i - 1), 0, 100, 100);
		CCSprite* numsaft = CCSprite::create("numbuttonaft.png", rectaft);

		// �v�Z�p�֐��|�C���^���R�[���o�b�N�ɓo�^����������
		/*
		auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(nc.*calcfunc[i], this));
		//���j���[�̍쐬�@pMenu�̒���numbutton�����
		auto pMenu = Menu::create(numbutton, NULL);
		pMenu->setPosition(ccp(visibleSize.width*i*.25, visibleSize.height / 2));
		this->addChild(pMenu, 1);
		*/

		if (i == 1)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc1, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 2)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc2, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 3)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc3, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 4)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc4, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 5)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc5, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 6)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc6, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 7)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc7, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 8)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc8, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 9)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc9, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 10)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(NextScene::calcfunc0, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 200));
			this->addChild(pMenu, 1);
		}
	}

	// �����Z�q�{�^�����쐬
	auto waruItem = MenuItemImage::create(
		"warubef.png",
		"waruaft.png",
		CC_CALLBACK_1(NextScene::warufunc, this));
	waruItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 4, visibleSize.height*.5 + 100));
	auto warumenu = Menu::create(waruItem, NULL);
	warumenu->setPosition(Vec2::ZERO);
	this->addChild(warumenu, 1);

	// �~���Z�q�{�^�����쐬
	auto kakeruItem = MenuItemImage::create(
		"kakerubef.png",
		"kakeruaft.png",
		CC_CALLBACK_1(NextScene::kakerufunc, this));
	kakeruItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 4, visibleSize.height*.5));
	auto kakerumenu = Menu::create(kakeruItem, NULL);
	kakerumenu->setPosition(Vec2::ZERO);
	this->addChild(kakerumenu, 1);

	// �|���Z�q�{�^�����쐬
	auto hikuItem = MenuItemImage::create(
		"hikubef.png",
		"hikuaft.png",
		CC_CALLBACK_1(NextScene::hikufunc, this));
	hikuItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 4, visibleSize.height*.5 - 100));
	auto hikumenu = Menu::create(hikuItem, NULL);
	hikumenu->setPosition(Vec2::ZERO);
	this->addChild(hikumenu, 1);

	// �{���Z�q�{�^�����쐬
	auto tasuItem = MenuItemImage::create(
		"tasubef.png",
		"tasuaft.png",
		CC_CALLBACK_1(NextScene::tasufunc, this));
	tasuItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 4, visibleSize.height*.5 - 200));
	auto tasumenu = Menu::create(tasuItem, NULL);
	tasumenu->setPosition(Vec2::ZERO);
	this->addChild(tasumenu, 1);

	// �����Z�q�{�^�����쐬
	auto equalItem = MenuItemImage::create(
		"equalbef.png",
		"equalaft.png",
		CC_CALLBACK_1(NextScene::equalfunc, this));
	equalItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 3, visibleSize.height*.5 - 200));
	auto equalmenu = Menu::create(equalItem, NULL);
	equalmenu->setPosition(Vec2::ZERO);
	this->addChild(equalmenu, 1);

	// �h�b�g�{�^�����쐬
	auto tenItem = MenuItemImage::create(
		"tenbef.png",
		"tenaft.png",
		CC_CALLBACK_1(NextScene::tenfunc, this));
	tenItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 2, visibleSize.height*.5 - 200));
	auto tenmenu = Menu::create(tenItem, NULL);
	tenmenu->setPosition(Vec2::ZERO);
	this->addChild(tenmenu, 1);

	// CLEAR���Z�q�{�^�����쐬
	auto clearItem = MenuItemImage::create(
		"clearbef.png",
		"clearaft.png",
		CC_CALLBACK_1(NextScene::clearfunc, this));
	clearItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 1, visibleSize.height*.5 + 200));
	auto clearmenu = Menu::create(clearItem, NULL);
	clearmenu->setPosition(Vec2::ZERO);
	this->addChild(clearmenu, 1);

	// CLEAREND���Z�q�{�^�����쐬
	auto clearendItem = MenuItemImage::create(
		"clearendbef.png",
		"clearendaft.png",
		CC_CALLBACK_1(NextScene::clearendfunc, this));
	clearendItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 2, visibleSize.height*.5 + 200));
	auto clearendmenu = Menu::create(clearendItem, NULL);
	clearendmenu->setPosition(Vec2::ZERO);
	this->addChild(clearendmenu, 1);

	// �����Z�q�{�^�����쐬
	auto leftItem = MenuItemImage::create(
		"leftbef.png",
		"leftaft.png",
		CC_CALLBACK_1(NextScene::leftfunc, this));
	leftItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 3, visibleSize.height*.5 + 200));
	auto leftmenu = Menu::create(leftItem, NULL);
	leftmenu->setPosition(Vec2::ZERO);
	this->addChild(leftmenu, 1);

	// �����Z�q�{�^�����쐬
	auto rightItem = MenuItemImage::create(
		"rightbef.png",
		"rightaft.png",
		CC_CALLBACK_1(NextScene::rightfunc, this));
	rightItem->setPosition(ccp(visibleSize.width*.5 - 300 + 100 * 4, visibleSize.height*.5 + 200));
	auto rightmenu = Menu::create(rightItem, NULL);
	rightmenu->setPosition(Vec2::ZERO);
	this->addChild(rightmenu, 1);

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

// �������Z�b�g����
void set_number(string s)
{
	if (cr.resultstr.length() >= 16)
	{
		cr.opera_flg = false;
		return;
	}

	if (dispnum->getString() == "0" || cr.opera_flg == true) dispnum->setString(s);
	else dispnum->setString(dispnum->getString() + s);
	cr.resultstr = dispnum->getString();
	cr.opera_flg = false;
}

// 文字列変換
template <typename T> std::string tostr(const T& t)
{
    std::ostringstream os; os<<t; return os.str();
}
// ���Z����
void calclation(char cal)
{
	stringstream str;
	double num;
	double result;

	str << cr.resultstr;
	str >> num;

	if (cr.opera_flg == true)
	{
		cr.opera = cal;
		return;
	}

	if (cr.opera == NULL)
	{
		cr.opera = cal;
		cr.resultnum = num;
		cr.opera_flg = true;
		return;
	}

	switch (cr.opera)
	{
	case '/':
		result = cr.resultnum / num;
		break;
	case '*':
		result = cr.resultnum * num;
		break;
	case '-':
		result = cr.resultnum - num;
		break;
	case '+':
		result = cr.resultnum + num;
		break;
	default:
		result = num;
		break;
	}
	cr.resultnum = result;
	cr.resultstr = tostr(result);
	dispnum->setString(tostr(result));

	cr.opera = cal;
	cr.opera_flg = true;
}

void NextScene::calcfunc1(Ref* pSender)
{
	set_number("1");
}
void NextScene::calcfunc2(Ref* pSender)
{
	set_number("2");
}
void NextScene::calcfunc3(Ref* pSender)
{
	set_number("3");
}

void NextScene::calcfunc4(Ref* pSender)
{
	set_number("4");
}

void NextScene::calcfunc5(Ref* pSender)
{
	set_number("5");
}

void NextScene::calcfunc6(Ref* pSender)
{
	set_number("6");
}

void NextScene::calcfunc7(Ref* pSender)
{
	set_number("7");
}

void NextScene::calcfunc8(Ref* pSender)
{
	set_number("8");
}

void NextScene::calcfunc9(Ref* pSender)
{
	set_number("9");
}

void NextScene::calcfunc0(Ref* pSender)
{
	set_number("0");
}

void NextScene::warufunc(Ref* pSender)
{
	calclation('/');
}

void NextScene::kakerufunc(Ref* pSender)
{
	calclation('*');
}

void NextScene::hikufunc(Ref* pSender)
{
	calclation('-');
}

void NextScene::tasufunc(Ref* pSender)
{
	calclation('+');
}

void NextScene::equalfunc(Ref* pSender)
{
	calclation('=');
}

void NextScene::tenfunc(Ref* pSender)
{
	set_number(".");
}

void NextScene::clearfunc(Ref* pSender)
{
	cr.resultstr = "0";
	cr.resultnum = 0;
	cr.opera = NULL;
	cr.opera_flg = false;
	dispnum->setString("0");
}

void NextScene::clearendfunc(Ref* pSender)
{
	dispnum->setString(tostr(cr.resultnum));
	cr.resultstr = "0";
	cr.opera_flg = true;
}

void NextScene::leftfunc(Ref* pSender)
{
}

void NextScene::rightfunc(Ref* pSender)
{
}
