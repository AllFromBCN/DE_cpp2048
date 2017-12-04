/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
블록 합체 알고리즘
연산자 오버로딩 (Map m1 + Block b1) : 맵에 블록 얹기
*/

#include "block.h"
#include <iostream>
#include <random>
#include <string>

using namespace std;

class Map{
public:
	int size;
	string **map;

	Map(){
		size = 4;
		make();
	}
	
	Map(int size){
		this->size = size; // main에서 size가 4이상인지 check해야함
		 make();
	}
	
	~Map(){
		delete[] map;
		map = NULL;
	}
	
	make(){
		random_device rd;
		mt19937_64 rng(rd());
		uniform_int_distribution<__int64> dist(1,size*size);
		
		map = new string*[size];
		for(int i=0;i<size;i++)
			map[i] = new string[size];
		
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size;j++)
				map[i][j] = "0";
		}
	}
	
	void operator+(Block b);
	bool check();
	void move(char input); // 방향키값 
};

void Map::operator+(Block b)
{
	int rand = dist(rng);
	int i,j;
	
	for(i=0; i<size; i++)
	{
		for(j=0;j<size;j++)
		{
			if(map[i][j] == "0")
				rand--;
				
			if(rand == 0)
				map[i][j] = b.num;
		}
	}
}

bool Map::check()
{
	int i,j;
	int center;
	int temp;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i%2 != j%2)
				continue;
			center = stoi(map[i][j]);
			
			if(i-1>=0){
				temp = stoi(map[i-1][j]);
				if(center == temp)
					return true;
			}
			
			if(j-1>=0){
				temp = stoi(map[i][j-1]);
				if(center == temp)
					return true;
			}
			
			if(j+1<size){
				temp = stoi(map[i][j+1]);
				if(center == temp)
					return true;
			}
			
			if(i+1<size){
				temp = stoi(map[i][j+1]);
				if(center == temp)
					return true;
			}
		}
	}
	return false;
}

void Map::move(char input)
{
	if(input == 'u')
	{
		for(int j=0;j<size;j++)
		{
			int* arr = new int[size];
			int i;
			
			for(i=0;i<size;i++)
				arr[i] = (map[i][j] == "0") ? 0 : 1;
			
			for(i=0;i<size;i++)
			{
				if(arr[i] == 1)
				{
					int num1 = stoi(map[i][j]);
					for(int k=i+1;k<size;k++)
					{
						if(arr[k] == 1)
						{
							int num2 = stoi(map[k][j]);
							if(num1 == num2)
							{
								map[i][j] = to_string(num1+num2);
								map[k][j] = "0";
								arr[k] = 0;
								break;
							}
						}
					}
				}	
			}
			
			int index = 0;
			for(i=0;i<size;i++)
			{
				if(arr[i] == 1)
				{
					if(index != i)
					{
						map[index][j] = map[i][j];
						map[i][j] = "0";
						arr[i] = 0;
						index++;
					}
				}
			}
		}
	}
	
	else if(input == 'd')
	{
		for(int j=0;j<size;j++)
		{
			int* arr = new int[size];
			int i;
			
			for(i=0;i<size;i++)
				arr[i] = (map[i][j] == "0") ? 0 : 1;
			
			for(i=size-1;i>=0;i--)
			{
				if(arr[i] == 1)
				{
					int num1 = stoi(map[i][j]);
					for(int k=i-1;k>=0;k--)
					{
						if(arr[k] == 1)
						{
							int num2 = stoi(map[k][j]);
							if(num1 == num2)
							{
								map[i][j] = to_string(num1+num2);
								map[k][j] = "0";
								arr[k] = 0;
								break;
							}
						}
					}
				}	
			}
			int index = size-1;
			for(i=size-1;i>=0;i--)
			{
				if(arr[i] == 1)
				{
					if(index != i)
					{
						map[index][j] = map[i][j];
						map[i][j] = "0";
						arr[i] = 0;
						index--;
					}
				}
			}
		}
	}
	
	else if(input == 'l')
	{
		for(int i=0;i<size;i++)
		{
			int* arr = new int[size];
			int j;
			
			for(j=0;j<size;j++)
				arr[j] = (map[i][j] == "0") ? 0 : 1;
			
			for(j=0;j<size;j++)
			{
				if(arr[j] == 1)
				{
					int num1 = stoi(map[i][j]);
					for(int k=j+1;k<size;k++)
					{
						if(arr[k] == 1)
						{
							int num2 = stoi(map[i][k]);
							if(num1 == num2)
							{
								map[i][j] = to_string(num1+num2);
								map[i][k] = "0";
								arr[k] = 0;
								break;
							}
						}
					}
				}	
			}
			int index = 0;
			for(j=0;j<size;j++)
			{
				if(arr[j] == 1)
				{
					if(index != i)
					{
						map[i][index] = map[i][j];
						map[i][j] = "0";
						arr[j] = 0;
						index++;
					}
				}
			}
		}
	}
	
	else if(input == 'r')
	{
		for(int i=0;i<size;i++)
		{
			int* arr = new int[size];
			int j;
			
			for(j=size-1;j>=0;j--)
				arr[j] = (map[i][j] == "0") ? 0 : 1;
			
			for(j=size-1;j>=0;j--)
			{
				if(arr[j] == 1)
				{
					int num1 = stoi(map[i][j]);
					for(int k=j-1;k>=0;k--)
					{
						if(arr[k] == 1)
						{
							int num2 = stoi(map[i][k]);
							if(num1 == num2)
							{
								map[i][j] = to_string(num1+num2);
								map[i][k] = "0";
								arr[k] = 0;
								break;
							}
						}
					}
				}	
			}
			int index = size-1;
			for(j=size-1;j>=0;j--)
			{
				if(arr[j] == 1)
				{
					if(index != i)
					{
						map[i][index] = map[i][j];
						map[i][j] = "0";
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
