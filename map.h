#pragma once
#ifndef MAP_H
#define MAP_H

#include "block.h"
#include "score.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Map{
    int size = 0;
	Score score;

public:
	Block **map;
    Map();
    ~Map();

	Block setMap(int);
    void operator+(Block b);
    bool check();
    void move(char input); // 방향키값
	Score operateScore() { return score; }
	int getSize() { return size; }
};

#endif

