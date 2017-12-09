//
// Created by 정수민 on 2017. 12. 5..
//
#define kDown 115 // to delete
#define kLeft 97 // to delete
#define kRight 100 // to delete

#include <iostream>
#include "block.h"
using namespace std;

Block::Block(int row, int col, int num, bool bonus){
    this->row = row;
    this->col = col;
    this->num = num;
    this->bonus = bonus;
}

Block::~Block(){};

int Block::getRow()
{ return row; }
int Block::getCol()
{ return col; }
int Block::getNum()
{ return num; }
bool Block::getBonus()
{ return bonus;};

void Block::setRow(int row)
{ this->row = row; }
void Block::setCol(int col)
{ this->col = col; }
void Block::setNum(int num)
{ this->num = num; }
void Block::setBonus(bool bonus)
{ this->bonus = bonus; }