#ifndef __NEXT_SCENE_H__
#define __NEXT_SCENE_H__

#include "cocos2d.h"

class NextScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// �v�Z�p�֐�
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
	// �v�Z�p�֐��|�C���^
	/*
	void(*calcfunc[])(cocos2d::Ref* pSender) = {
		this->calcfunc1, this->calcfunc2, this->calcfunc3, this->calcfunc4, this->calcfunc5, this->calcfunc6, this->calcfunc7, this->calcfunc8, this->calcfunc9, this->calcfunc0
	};
	*/

	// implement the "static create()" method manually
	CREATE_FUNC(NextScene);
};

#endif // __NEXT_SCENE_H__
