#ifndef VISUAL_H
#define VISUAL_H

//
// Created by 정수민 on 2017. 12. 9..
//
/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/
#include "map.h"
#include "score.h"
#include <iostream>
#include <string>

using namespace std;

class Visual {
	int size;
	Map map;

public:
	Visual() {}
	~Visual() {}

	void show();
	void start();
	void setMap(int);
	
};
#endif //VISUAL_H
