#define kDown 115 // to delete
#define kLeft 97 // to delete
#define kRight 100 // to delete

#include <iostream>
#include "block.h"

using namespace std;

Block::Block(){}

Block::Block(int num, bool bonus){
	this->num = num;
	this->bonus = bonus;
}

Block::~Block(){}

int Block::getNum()
{ return num; }
bool Block::getBonus()
{ return bonus;};

void Block::setNum(int num)
{ this->num = num; }
void Block::setBonus(bool bonus)
{ this->bonus = bonus; }
