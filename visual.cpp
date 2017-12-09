/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/

#define defaultSize 4

#include "map.h"
#include "score.h"
#include "visual.h"
#include <iostream>
#include <string>

using namespace std;

void Visual::show()
{
	cout << "Score : " << map.operateScore().getScore()<< endl;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			char temp[5];
			for (int k = 0; k<4; k++)
			{
				temp[k] = '_';
			}
			temp[4] = ' ';

			/*
			int num = map[i][j]; //@가 없는 map만 실행됨.. @을 제거하는 방법을 찾아야함 todo
			int k=3;
			while(1)
			{
			if(num!=0)
			{
			temp[k--] = num%10;
			num = num/10;
			}
			else break;
			}
			if(map[i][j].find('@')) // 왜 찾아지지? 그래서 차라리 map을 int로만 만들고, bonus인지를 따로 체크하는 array만드는것은?
			{
			temp[k] = '@';
			}*/

			cout << temp;
		}
		cout << endl;
	}
};

Map Visual::start()
{
	string enter;
	cout << "You make the 2048 tile!" << endl;
	cout << "You can use the A W D S button" << endl;
	cout << "If you want to start with 4x4 map, then enter the 's'" << endl;
	cout << "If you want to start with a map larger then 4X4, then enter the number between 5 and 9" << endl;
	while (1)
	{
		getline(cin, enter);
		try {
			if (enter == "s")
			{
				setMap(defaultSize);
				return;
				//Map orgMap(defaultSize); // original Map generation
				//return orgMap;
			}
			else if (enter >= "5"&& enter <= "9")
			{
				setMap(stoi(enter));
				return;
				//Map orgMap(stoi(enter));
				//return orgMap;
			}
			else
				throw enter;
		}
		catch (string exception) {
			cout << "You entered the " << exception << "." << endl;
			cerr << "Out of range. Please re-enter" << endl;
		}
	}
}

void Visual::setMap(int size)
{
	this->size = size;
	this->map = Map(size);
}
