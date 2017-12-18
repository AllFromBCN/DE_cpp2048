#include "score.h"

using namespace std;

Score::Score() {}
Score::~Score() {}

void Score::addScore(Block& b1, Block& b2)
{
	int temp = b1.getNum() + b2.getNum();
	if (temp >= 10000)
		throw 'a';

	if (b1.getBonus() == true)
	{
		temp *= 2;
		b1.setBonus(false);
	}
	if (b2.getBonus() == true)
	{
		temp *= 2;
		b2.setBonus(false);
	}		
	score += temp;
}
