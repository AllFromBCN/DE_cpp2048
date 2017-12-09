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

