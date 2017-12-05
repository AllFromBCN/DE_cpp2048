
#define kUp 119 // to delete
#define kDown 115 // to delete
#define kLeft 97 // to delete
#define kRight 100 // to delete

#include <iostream>
#include <block.h>
using namespace std;

Block::Block(int row, int col, int num){
  this->row = row;
  this->col = col;
  this->num = num;
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
