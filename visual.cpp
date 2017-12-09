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

void Visual::show(Map map)
{
	cout << "Score : " << map.operateScore().getScore()<< endl;
	for (int i = 0; i<map.getSize(); i++)
	{
		for (int j = 0; j<map.getSize(); j++)
		{
			char temp[6];
			for (int k = 0; k<4; k++)
			{
				temp[k] = '_';
			}
			temp[4] = ' ';
			temp[5] = 0;

			//cout << "temp : " << temp << endl;
			int num = map.map[i][j].getNum();
			//cout << "num : " << num;
			int k=3;
			if (num != -1)
			{
				while (1)
				{
					if (num != 0)
					{
						temp[k--] = (num % 10) + 48;
						num = num / 10;
					}
					else break;
				}
				//cout << "temp : " << temp << endl;
				if (map.map[i][j].getBonus())
				{
					temp[k] = '@';
				}
			}
			cout << temp;
		}
		cout << endl;
	}
};
