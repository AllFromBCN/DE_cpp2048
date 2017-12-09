#include "score.h"
#include <iostream>

using namespace std;

Score::Score() {}
Score::~Score() {}

void Score::addScore(Block b1, Block b2)
{
	int temp = b1.getNum + b2.getNum;
	if (b1.getBonus == true)
	{temp *= 2;}
	if (b2.getBonus == true)
	{temp *= 2;}
	score += temp;
}
