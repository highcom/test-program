#include <sstream>
#include "CalculationScene.h"
#include "HelloWorldScene.h"
#include "CalcResult.h"

using namespace std;

USING_NS_CC;

void set_number(string);
void delete_before_chain();
void delete_after_chain();
void calclation(char);
void create_chain();

Scene* CalculationScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CalculationScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

//void(*calcfunc[])(cocos2d::Ref* pSender) = { calcfunc1, calcfunc2, calcfunc3, calcfunc4, calcfunc5, calcfunc6, calcfunc7, calcfunc8, calcfunc9, calcfunc0 };

bool CalculationScene::init()
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
		CC_CALLBACK_1(CalculationScene::menuCloseCallback, this));

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
	auto disp = LayerColor::create(Color4B::WHITE, visibleSize.width, 70);
	disp->setPosition(Vec2(0, visibleSize.height*.9));
	this->addChild(disp, 1);

	crp = new CalcResult();
	dispnum = Label::createWithTTF(crp->resultstr, "fonts/arial.ttf", 36);
	//auto dispnum = Label::createWithTTF(crp->resultnum, "fonts/arial.ttf", 36);
	dispnum->setColor(ccc3(0, 0, 0));
	dispnum->setPosition(Vec2(visibleSize.width*.5, visibleSize.height*.95));
	this->addChild(dispnum, 1);

	// 関数ポインタの登録はあっているが、関数ポインタをコールバックに登録はできないようだ
	CalculationScene nc;
	void (CalculationScene::*calcfunc[10])(cocos2d::Ref* pSender) = { &CalculationScene::calcfunc1, &CalculationScene::calcfunc2, &CalculationScene::calcfunc3, &CalculationScene::calcfunc4, &CalculationScene::calcfunc5,
															   &CalculationScene::calcfunc6, &CalculationScene::calcfunc7, &CalculationScene::calcfunc8, &CalculationScene::calcfunc9, &CalculationScene::calcfunc0};
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
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc1, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 2)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc2, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 3)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc3, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 4)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc4, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 5)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc5, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 6)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc6, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5));
			this->addChild(pMenu, 1);
		}
		else if (i == 7)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc7, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 8)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc8, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 9)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc9, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 + 100));
			this->addChild(pMenu, 1);
		}
		else if (i == 10)
		{
			auto numbutton = MenuItemSprite::create(numsbef, numsaft, CC_CALLBACK_1(CalculationScene::calcfunc0, this));
			auto pMenu = Menu::create(numbutton, NULL);
			pMenu->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * ((i - 1) % 3 + 1), visibleSize.height*.5 - 200));
			this->addChild(pMenu, 1);
		}
	}

	// ÷演算子ボタンを作成
	auto waruItem = MenuItemImage::create(
		"warubef.png",
		"waruaft.png",
		CC_CALLBACK_1(CalculationScene::warufunc, this));
	waruItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 4, visibleSize.height*.5 + 100));
	auto warumenu = Menu::create(waruItem, NULL);
	warumenu->setPosition(Vec2::ZERO);
	this->addChild(warumenu, 1);

	// ×演算子ボタンを作成
	auto kakeruItem = MenuItemImage::create(
		"kakerubef.png",
		"kakeruaft.png",
		CC_CALLBACK_1(CalculationScene::kakerufunc, this));
	kakeruItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 4, visibleSize.height*.5));
	auto kakerumenu = Menu::create(kakeruItem, NULL);
	kakerumenu->setPosition(Vec2::ZERO);
	this->addChild(kakerumenu, 1);

	// －演算子ボタンを作成
	auto hikuItem = MenuItemImage::create(
		"hikubef.png",
		"hikuaft.png",
		CC_CALLBACK_1(CalculationScene::hikufunc, this));
	hikuItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 4, visibleSize.height*.5 - 100));
	auto hikumenu = Menu::create(hikuItem, NULL);
	hikumenu->setPosition(Vec2::ZERO);
	this->addChild(hikumenu, 1);

	// ＋演算子ボタンを作成
	auto tasuItem = MenuItemImage::create(
		"tasubef.png",
		"tasuaft.png",
		CC_CALLBACK_1(CalculationScene::tasufunc, this));
	tasuItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 4, visibleSize.height*.5 - 200));
	auto tasumenu = Menu::create(tasuItem, NULL);
	tasumenu->setPosition(Vec2::ZERO);
	this->addChild(tasumenu, 1);

	// ＝演算子ボタンを作成
	auto equalItem = MenuItemImage::create(
		"equalbef.png",
		"equalaft.png",
		CC_CALLBACK_1(CalculationScene::equalfunc, this));
	equalItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 3, visibleSize.height*.5 - 200));
	auto equalmenu = Menu::create(equalItem, NULL);
	equalmenu->setPosition(Vec2::ZERO);
	this->addChild(equalmenu, 1);

	// ドットボタンを作成
	auto tenItem = MenuItemImage::create(
		"tenbef.png",
		"tenaft.png",
		CC_CALLBACK_1(CalculationScene::tenfunc, this));
	tenItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 2, visibleSize.height*.5 - 200));
	auto tenmenu = Menu::create(tenItem, NULL);
	tenmenu->setPosition(Vec2::ZERO);
	this->addChild(tenmenu, 1);

	// CLEAR演算子ボタンを作成
	auto clearItem = MenuItemImage::create(
		"clearbef.png",
		"clearaft.png",
		CC_CALLBACK_1(CalculationScene::clearfunc, this));
	clearItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 1, visibleSize.height*.5 + 200));
	auto clearmenu = Menu::create(clearItem, NULL);
	clearmenu->setPosition(Vec2::ZERO);
	this->addChild(clearmenu, 1);

	// CLEAREND演算子ボタンを作成
	auto clearendItem = MenuItemImage::create(
		"clearendbef.png",
		"clearendaft.png",
		CC_CALLBACK_1(CalculationScene::clearendfunc, this));
	clearendItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 2, visibleSize.height*.5 + 200));
	auto clearendmenu = Menu::create(clearendItem, NULL);
	clearendmenu->setPosition(Vec2::ZERO);
	this->addChild(clearendmenu, 1);

	// ←演算子ボタンを作成
	auto leftItem = MenuItemImage::create(
		"leftbef.png",
		"leftaft.png",
		CC_CALLBACK_1(CalculationScene::leftfunc, this));
	leftItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 3, visibleSize.height*.5 + 200));
	auto leftmenu = Menu::create(leftItem, NULL);
	leftmenu->setPosition(Vec2::ZERO);
	this->addChild(leftmenu, 1);

	// →演算子ボタンを作成
	auto rightItem = MenuItemImage::create(
		"rightbef.png",
		"rightaft.png",
		CC_CALLBACK_1(CalculationScene::rightfunc, this));
	rightItem->setPosition(ccp(visibleSize.width*.5 - 250 + 100 * 4, visibleSize.height*.5 + 200));
	auto rightmenu = Menu::create(rightItem, NULL);
	rightmenu->setPosition(Vec2::ZERO);
	this->addChild(rightmenu, 1);

	return true;
}

void CalculationScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	delete_before_chain();
	delete_after_chain();
	delete crp;
	Director::getInstance()->replaceScene(HelloWorld::createScene());

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

// 数字をセットする
void set_number(string s)
{
	if (crp->resultstr.length() >= 16)
	{
		crp->opera_flg = false;
		return;
	}

	delete_after_chain();

	if (dispnum->getString() == "0" || crp->opera_flg == true) dispnum->setString(s);
	else dispnum->setString(dispnum->getString() + s);
	crp->resultstr = dispnum->getString();
	crp->opera_flg = false;
}

void delete_before_chain()
{
	int i, j;
	CalcResult *curcrp;
	CalcResult *delcrp[3] = { NULL, NULL, NULL };
	i = 0;
	j = 0;

	curcrp = crp;
	// 最大３回分の次チェーンを削除対象とする（前に戻れるのが３回までだから）
	for (i = 0; i < 3; i++)
	{
		if (curcrp->bef != NULL)
		{
			delcrp[j] = curcrp->bef;
			curcrp = curcrp->bef;
			j++;
		}
	}
	// 削除対象の結果を削除する
	for (i = 0; i < 3; i++)
	{
		if (delcrp[i] != NULL) delete delcrp[i];
	}

	// 現在の次チェーンのリンクを消す
	crp->bef = NULL;
}

void delete_after_chain()
{
	int i, j;
	CalcResult *curcrp;
	CalcResult *delcrp[3] = {NULL, NULL, NULL};
	i = 0;
	j = 0;

	curcrp = crp;
	// 最大３回分の次チェーンを削除対象とする（前に戻れるのが３回までだから）
	for (i = 0; i < 3; i++)
	{
		if (curcrp->aft != NULL)
		{
			delcrp[j] = curcrp->aft;
			curcrp = curcrp->aft;
			j++;
		}
	}
	// 削除対象の結果を削除する
	for (i = 0; i < 3; i++)
	{
		if (delcrp[i] != NULL) delete delcrp[i];
	}

	// 現在の次チェーンのリンクを消す
	crp->aft = NULL;
}

// 文字列変換
template <typename T> std::string tostr(const T& t)
{
    std::ostringstream os; os<<t; return os.str();
}
// 演算する
void calclation(char cal)
{
	stringstream str;
	double num;
	double result;

	str << crp->resultstr;
	str >> num;

	if (crp->opera_flg == true)
	{
		crp->opera = cal;
		return;
	}

	if (crp->opera == 0x00)
	{
		crp->opera = cal;
		crp->resultnum = num;
		crp->opera_flg = true;
		return;
	}

	switch (crp->opera)
	{
	case '/':
		result = crp->resultnum / num;
		break;
	case '*':
		result = crp->resultnum * num;
		break;
	case '-':
		result = crp->resultnum - num;
		break;
	case '+':
		result = crp->resultnum + num;
		break;
	default:
		result = num;
		break;
	}
	crp->resultnum = result;
	crp->resultstr = tostr(result);
	dispnum->setString(tostr(result));

	crp->opera = cal;
	crp->opera_flg = true;
}

void create_chain()
{
	if (crp->opera_flg) return;
	// 現在の結果をコピーしたインスタンスを作成
	CalcResult *newcrp = new CalcResult(*crp);
	// 現在の結果と新しい結果を相互リンクする
	crp->aft = newcrp;
	newcrp->bef = crp;
	// 新しい結果をカレントとする
	crp = newcrp;

	// 過去３回以前の状態は削除する
	CalcResult *delcrp = crp;
	for (int i = 0; i < 3; i++)
	{
		if (delcrp->bef != NULL)
		{
			if (i == 2)
			{
				delete delcrp->bef;
				delcrp->bef = NULL;
			}
			else
			{
				delcrp = delcrp->bef;
			}
		}
	}
}

CalcResult::CalcResult()
{
	resultstr = "0";
	resultnum = 0;
	opera = 0x00;
	opera_flg = false;
	bef = NULL;
	aft = NULL;
}

CalcResult::~CalcResult()
{
	log("delete complete");
}

void CalculationScene::calcfunc1(Ref* pSender)
{
	set_number("1");
}
void CalculationScene::calcfunc2(Ref* pSender)
{
	set_number("2");
}
void CalculationScene::calcfunc3(Ref* pSender)
{
	set_number("3");
}

void CalculationScene::calcfunc4(Ref* pSender)
{
	set_number("4");
}

void CalculationScene::calcfunc5(Ref* pSender)
{
	set_number("5");
}

void CalculationScene::calcfunc6(Ref* pSender)
{
	set_number("6");
}

void CalculationScene::calcfunc7(Ref* pSender)
{
	set_number("7");
}

void CalculationScene::calcfunc8(Ref* pSender)
{
	set_number("8");
}

void CalculationScene::calcfunc9(Ref* pSender)
{
	set_number("9");
}

void CalculationScene::calcfunc0(Ref* pSender)
{
	set_number("0");
}

void CalculationScene::warufunc(Ref* pSender)
{
	create_chain();
	calclation('/');
}

void CalculationScene::kakerufunc(Ref* pSender)
{
	create_chain();
	calclation('*');
}

void CalculationScene::hikufunc(Ref* pSender)
{
	create_chain();
	calclation('-');
}

void CalculationScene::tasufunc(Ref* pSender)
{
	create_chain();
	calclation('+');
}

void CalculationScene::equalfunc(Ref* pSender)
{
	create_chain();
	calclation('=');
}

void CalculationScene::tenfunc(Ref* pSender)
{
	if (crp->resultstr.length() >= 16 || crp->resultstr.find(".") != string::npos)
	{
		crp->opera_flg = false;
		return;
	}

	if (dispnum->getString() == "0" || crp->opera_flg == true) dispnum->setString("0.");
	else dispnum->setString(dispnum->getString() + ".");
	crp->resultstr = dispnum->getString();
	crp->opera_flg = false;
}

void CalculationScene::clearfunc(Ref* pSender)
{
	crp->resultstr = "0";
	crp->resultnum = 0;
	crp->opera = 0x00;
	crp->opera_flg = false;
	dispnum->setString("0");
}

void CalculationScene::clearendfunc(Ref* pSender)
{
	if (crp->opera_flg == true)
	{
		dispnum->setString("0");
	}
	else
	{
		dispnum->setString("0");
		crp->resultstr = "0";
	}
	crp->opera_flg = true;
}

void CalculationScene::leftfunc(Ref* pSender)
{
	if (crp->bef != NULL)
	{
		crp = crp->bef;
		dispnum->setString(crp->resultstr);
	}
}

void CalculationScene::rightfunc(Ref* pSender)
{
	if (crp->aft != NULL)
	{
		crp = crp->aft;
		dispnum->setString(crp->resultstr);
	}
}
