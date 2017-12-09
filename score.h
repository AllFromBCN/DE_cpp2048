/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
*/

#include "map.h"
#include "block.h"
#include <iostream>

using namespace std;

class Score{
	int score = 0;

public:
	Score();
	~Score();
	void addScore(Block, Block);
	int getScore();
};
