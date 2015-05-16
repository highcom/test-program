#ifndef __NEXT_SCENE_H__
#define __NEXT_SCENE_H__

#include "cocos2d.h"

class CalculationScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// androidボタンイベント
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	// 計算用関数
	void calcfunc1(cocos2d::Ref* pSender);
	void calcfunc2(cocos2d::Ref* pSender);
	void calcfunc3(cocos2d::Ref* pSender);
	void calcfunc4(cocos2d::Ref* pSender);
	void calcfunc5(cocos2d::Ref* pSender);
	void calcfunc6(cocos2d::Ref* pSender);
	void calcfunc7(cocos2d::Ref* pSender);
	void calcfunc8(cocos2d::Ref* pSender);
	void calcfunc9(cocos2d::Ref* pSender);
	void calcfunc0(cocos2d::Ref* pSender);
	// 計算用関数ポインタ
	/*
	void(*calcfunc[])(cocos2d::Ref* pSender) = {
		this->calcfunc1, this->calcfunc2, this->calcfunc3, this->calcfunc4, this->calcfunc5, this->calcfunc6, this->calcfunc7, this->calcfunc8, this->calcfunc9, this->calcfunc0
	};
	*/

	// 演算子関数
	void warufunc(cocos2d::Ref* pSender);
	void kakerufunc(cocos2d::Ref* pSender);
	void hikufunc(cocos2d::Ref* pSender);
	void tasufunc(cocos2d::Ref* pSender);
	void equalfunc(cocos2d::Ref* pSender);
	void tenfunc(cocos2d::Ref* pSender);
	void leftfunc(cocos2d::Ref* pSender);
	void rightfunc(cocos2d::Ref* pSender);
	void clearfunc(cocos2d::Ref* pSender);
	void clearendfunc(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(CalculationScene);
};

#endif // __NEXT_SCENE_H__
