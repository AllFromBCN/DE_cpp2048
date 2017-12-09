/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
블록 합체 알고리즘
연산자 오버로딩 (Map m1 + Block b1) : 맵에 블록 얹기
*/

#pragma once
#ifndef MAP_H
#define MAP_H

#include "block.h"
#include <iostream>
#include <random>

using namespace std;

class Map{
public:
	int size;
	Block **map;
	Map(int s);
	~Map();

	void operator+(Block b);
	bool check();
	void move(char input); // 방향키값 
};

#endif
