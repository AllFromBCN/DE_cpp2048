#include "map.h"
#include "block.h"
#include <iostream>
#include <random>

using namespace std;

Map::Map(int s) {
	this->size = s;
	map = new Block*[s];
	for (int i = 0; i<s; i++)
		map[i] = new Block[s];

}

Map::~Map() {
	delete[] map;
	map = NULL;
}

void Map::operator+(Block b)
{
	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<__int64> dist(1, size*size); // random variable 만들기 위한 코드 

	int rand = dist(rng);
	int i,j;

	for(i=0; i<size; i++)
	{
		for(j=0;j<size;j++)
		{
			if(map[i][j].num == 0)
			rand--;

			if(rand == 0)
			map[i][j].num = b.num;
		}
	}
}

bool Map::check()
{
	int i, j;
	int center;
	int temp;

	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size; j++)
		{
			if (i % 2 != j % 2)
				continue;
			center = map[i][j].num;

			if (i - 1 >= 0) {
				temp = map[i - 1][j].num;
				if (center == temp)
					return true;
			}

			if (j - 1 >= 0) {
				temp = map[i][j - 1].num;
				if (center == temp)
					return true;
			}

			if (j + 1<size) {
				temp = map[i][j + 1].num;
				if (center == temp)
					return true;
			}

			if (i + 1<size) {
				temp = map[i][j + 1].num;
				if (center == temp)
					return true;
			}
		}
	}
	return false;
}

void Map::move(char input)
{
	if (input == 'u')
	{
		for (int j = 0; j<size; j++)
		{
			int* arr = new int[size];
			int i;

			for (i = 0; i<size; i++)
				arr[i] = (map[i][j].num == 0) ? 0 : 1;

			for (i = 0; i<size; i++)
			{
				if (arr[i] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = i + 1; k<size; k++)
					{
						if (arr[k] == 1)
						{
							int num2 = map[k][j].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[k][j].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}

			int index = 0;
			for (i = 0; i<size; i++)
			{
				if (arr[i] == 1)
				{
					if (index != i)
					{
						map[index][j] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[i] = 0;
						index++;
					}
				}
			}
		}
	}

	else if (input == 'd')
	{
		for (int j = 0; j<size; j++)
		{
			int* arr = new int[size];
			int i;

			for (i = 0; i<size; i++)
				arr[i] = (map[i][j].num == 0) ? 0 : 1;

			for (i = size - 1; i >= 0; i--)
			{
				if (arr[i] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = i - 1; k >= 0; k--)
					{
						if (arr[k] == 1)
						{
							int num2 = map[k][j].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[k][j].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = size - 1;
			for (i = size - 1; i >= 0; i--)
			{
				if (arr[i] == 1)
				{
					if (index != i)
					{
						map[index][j] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[i] = 0;
						index--;
					}
				}
			}
		}
	}

	else if (input == 'l')
	{
		for (int i = 0; i<size; i++)
		{
			int* arr = new int[size];
			int j;

			for (j = 0; j<size; j++)
				arr[j] = (map[i][j].num == 0) ? 0 : 1;

			for (j = 0; j<size; j++)
			{
				if (arr[j] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = j + 1; k<size; k++)
					{
						if (arr[k] == 1)
						{
							int num2 = map[i][k].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[i][k].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = 0;
			for (j = 0; j<size; j++)
			{
				if (arr[j] == 1)
				{
					if (index != i)
					{
						map[i][index] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[j] = 0;
						index++;
					}
				}
			}
		}
	}

	else if (input == 'r')
	{
		for (int i = 0; i<size; i++)
		{
			int* arr = new int[size];
			int j;

			for (j = size - 1; j >= 0; j--)
				arr[j] = (map[i][j].num == 0) ? 0 : 1;

			for (j = size - 1; j >= 0; j--)
			{
				if (arr[j] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = j - 1; k >= 0; k--)
					{
						if (arr[k] == 1)
						{
							int num2 = map[i][k].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[i][k].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = size - 1;
			for (j = size - 1; j >= 0; j--)
			{
				if (arr[j] == 1)
				{
					if (index != i)
					{
						map[i][index] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[j] = 0;
						index--;
					}
				}
			}
		}
	}

	else
	{
		//방향키 입력 다시하도록 시키기..? 
	}
}
