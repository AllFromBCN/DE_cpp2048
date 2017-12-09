//
// Created by 정수민 on 2017. 12. 9..
//

#pragma once
#ifndef MAP_H
#define MAP_H

#include "block.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Map{
<<<<<<< HEAD
    int size = 0;

public:
    Block **map;
    Map();
    Map(int s);
    ~Map();

    void operator+(Block b);
    bool check();
    void move(char input); // 방향키값
};

#endif
=======
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
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
