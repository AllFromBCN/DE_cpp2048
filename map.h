#ifndef MAP_H
#define MAP_H

#include "score.h"

using namespace std;

class Map : public Score
{
    int size = 0;
	int b_count = 0; // bonus count -> 10번마다 bonus나오게

public:
	Block **map;
	Map();
    ~Map();

	void setSize(int);
	int getSize();
	int getScore();

	int countEmpty();
	void operator+();
	void operator+(int);
	int check();
    void move(char input); // 방향키값
};
#else
#endif
