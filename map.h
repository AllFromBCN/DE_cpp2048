#ifndef MAP_H
#define MAP_H

#include "score.h"

using namespace std;

class Map{
    int size = 0;
	Score map_score;
	int b_count = 0; // bonus count -> 10번마다 bonus나오게

public:
	Block **map;
	Map();
    ~Map();

	void setSize(int);
	int getSize();
	int showScore();

	int countEmpty();
	void operator+();
	void operator+(int);
	bool check();
    void move(char input); // 방향키값
};
#else
#endif

