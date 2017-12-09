#define kUp 119 // to delete
#define kDown 115 // to delete
#define kLeft 97 // to delete
#define kRight 100 // to delete

#include <iostream>
#include "block.h"
using namespace std;

Block::Block()
{
	this->row = -1;
	this->col = -1;
	this->num = 0;
	this->bonus = false;
}
Block::Block(int row, int col, int num, bool bonus) {
	this->row = row;
	this->col = col;
	this->num = num;
	this->bonus = bonus;
};

/*
template <typename T>
void Block::input(T& key)
{
   int key=getch();
   switch(key)
   {
     case kUp:
     case kDown:
     case kLeft:
     case kRight:
   }
}
void Block::input(int bonus)
{
 this->num = bonus;
}
*/
