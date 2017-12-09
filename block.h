/*
기본사항 : 생성자, 소멸자, 복사생성자, this
상속 : 기본블록, 아이템블록
Template : input으로 방향키 혹은 알파벳 //todo
오버로딩 : input으로 int값 (일부 template 특수화)
*/
#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

using namespace std;

class Block{
    int row = -1;
    int col = -1;
    int num = -1;
    bool bonus = false;
public:
    Block();
    Block(int, int, int, bool);
    ~Block();

    // getters
    int getRow();
    int getCol();
    int getNum();
    bool getBonus();

    //setters
    void setRow(int);
    void setCol(int);
    void setNum(int);
    void setBonus(bool);

    template <typename T>
    void input(T& inputDir);
    void input(int);
};

#endif
