/*
기본사항 : 생성자, 소멸자, 복사생성자, this
상속 : 기본블록, 아이템블록
Template : input으로 방향키 혹은 알파벳 //todo
오버로딩 : input으로 int값 (일부 template 특수화)
*/

#ifndef BLOCK_H
#define BLCOK_H

#include <iostream>
using namespace std;

class Block{
  int row;
  int col;
  int num;
  bool bonus = false;

public:
  Block(int, int, int){

  };
  ~Block();
  template <typename T>
  void input(T& inputDir);
  void input(int);
}

#endif
