/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/

#ifndef VISUAL_H
#define VISUAL_H

#include "map.h"
#include "score.h"

using namespace std;

class Visual {
public:
	Visual() {}
	~Visual() {}

	void show(Map& map) const;
    char input(char key);
};
#else
#endif
