/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
*/
#ifndef SCORE_H
#define SCORE_H

#include "block.h"

using namespace std;

class Score{

public:
	int score = 0;
	Score();
	~Score();
	void addScore(Block&, Block&);
	virtual int getScore() = 0;
};
#else
#endif
