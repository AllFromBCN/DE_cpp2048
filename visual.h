/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/

#ifndef VISUAL_H
#define VISUAL_H

#include "score.h"
#include "map.h"
#include <iostream>
#include <string>

using namespace std;

class Visual {
public:
	Visual() {}
	~Visual() {}

	void show(Map);
	
};
#endif //VISUAL_H
