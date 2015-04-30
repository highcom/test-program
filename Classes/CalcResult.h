#ifndef __CALC_RESULT_H__
#define __CALC_RESULT_H__

#include "cocos2d.h"
#include <string>
using namespace std;
class CalcResult
{
public:
	string resultstr;
	double resultnum;
	char opera;
	bool opera_flg;

	CalcResult *bef;
	CalcResult *aft;

	CalcResult();
	~CalcResult();
};

CalcResult *crp;
cocos2d::Label *dispnum;

#endif // __CALC_RESULT_H__