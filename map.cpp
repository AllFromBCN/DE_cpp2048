#include "map.h"
#include <stdlib.h>
#include <random>

using namespace std;

Map::Map() {
	map = new Block*[9];
	for (int i = 0; i<9; i++)
		map[i] = new Block[9];
}

Map::~Map() {
    delete[] map;
    map = NULL;
}

void Map::setSize(int s) {
	this -> size = s;
}

int Map::getSize() {
	return size;
}

int Map::showScore(){
	return map_score.getScore();
}

int Map::countEmpty(){
	int count = 0;
	for (int i=0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getNum() == -1)
				count++;
		}
	}
	return count;
}

int make_random(int max){
	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<__int64> dist(1, max); // random variable 만들기 위한 코드 
	return dist(rng);
}

void Map::operator+() {
	int temp = (make_random(2) % 2 == 0) ? 2 : 4;
	operator+(temp);
}

void Map::operator+(int num){
	//int ranNum = rand() % (size*size) + 1;
	cout << "here1" << endl;
	int ranNum = make_random(countEmpty());
	cout << "here2" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getNum() == -1)
				ranNum--;

			if (ranNum == 0){
				map[i][j].setNum(num);
				if (b_count == 10){
					map[i][j].setBonus(true);
					b_count = 0;
				}
				else 
					b_count++;
				return;
			}
		}
	}
}

bool Map::check()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i % 2 != j % 2)
				continue;
			int center = map[i][j].getNum();

			if (i - 1 >= 0 && center == map[i - 1][j].getNum())
					return true;

			if (j - 1 >= 0 && center == map[i][j - 1].getNum())
					return true;

			if (j + 1 < size && center == map[i][j + 1].getNum())
					return true;

			if (i + 1 < size && center == map[i+1][j].getNum())
					return true;
		}
	}
	return false;
}

void Map::move(char input)
{
	if (input == 'u' || input == 'd') {
		bool btemp = (input == 'u') ? true : false;

		for (int j = 0; j < size; j++) {
			int *arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = (map[i][j].getNum() == -1) ? 0 : 1;
				
			int index = btemp ? 0 : size - 1;
			int cnt = btemp ? +1 : -1;

			for (int m = 0; m < size; m++) {
				int i = btemp ? m : size - m - 1;
				if (arr[i] == 1) {
					int num1 = map[i][j].getNum();
					int k = btemp ? i + 1 : i - 1;

					while (k < size && k >= 0) {
						if (arr[k] == 1) {
							int num2 = map[k][j].getNum();
							if (num1 == num2) {
								map_score.addScore(map[i][j], map[k][j]);
								map[i][j].setNum(num1 + num2);
								map[k][j].setNum(-1);
								arr[k] = 0;
								break;
							}
						}
						else
							k += cnt;
					}
				}
			}
			for (int m = 0; m < size; m++) {
				int i = btemp ? m : size - m - 1;
				if (arr[i] == 1) {
					if (index != i) {
						map[index][i].setNum(map[i][j].getNum());
						map[index][i].setBonus(map[i][j].getBonus());
						map[i][j].setNum(-1);
						map[i][j].setBonus(0);
						arr[i] = 0;
					}
					index += cnt;
				}
			}
		}
	}
	else if (input == 'l' || input == 'r') {
		bool btemp = (input == 'l') ? true : false;

		for (int i = 0; i < size; i++) {
			int *arr = new int[size];

			for (int j = 0; j < size; j++)
				arr[j] = (map[i][j].getNum() == -1) ? 0 : 1;
				
			int index = btemp ? 0 : size - 1;
			int cnt = btemp ? +1 : -1;

			for (int m = 0; m < size; m++) {
				int j = btemp ? m : size - m - 1;
				if (arr[j] == 1) {
					int num1 = map[i][j].getNum();
					int k = btemp ? j + 1 : j - 1;

					while (k < size && k >= 0) {
						if (arr[k] == 1) {
							int num2 = map[i][k].getNum();
							if (num1 == num2) {
								map_score.addScore(map[i][j], map[i][k]);
								map[i][j].setNum(num1 + num2);
								map[i][k].setNum(-1);
								arr[k] = 0;
								break;
							}
						}
						else
							k += cnt;
					}
				}
			}
			for (int m = 0; m < size; m++) {
				int j = btemp ? m : size - m - 1;
				if (arr[j] == 1) {
					if (index != j) {
						map[i][index].setNum(map[i][j].getNum());
						map[i][index].setBonus(map[i][j].getBonus());
						map[i][j].setNum(-1);
						map[i][j].setBonus(0);
						arr[j] = 0;
					}
					index += cnt;
				}
			}
		}
	}
}
