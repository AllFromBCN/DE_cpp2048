/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/

//#define defaultSize 4

#include "visual.h"

using namespace std;

void Visual::show(Map& map) const
{
	cout << "Score : " << map.showScore()<< endl;
	for (int i = 0; i<map.getSize(); i++)
	{
		for (int j = 0; j<map.getSize(); j++)
		{
			char temp[6];
			for (int k = 0; k<4; k++)
				temp[k] = '_';
			temp[4] = ' ';
			temp[5] = 0;
			
			int num = map.map[i][j].getNum();
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
				if (map.map[i][j].getBonus())
					temp[k] = '@';
			}
			cout << temp;
		}
		cout << endl;
	}
};

char Visual::input(char key)
{
    if (key=='a') // LEFT
        return 'l';

    else if (key=='w') // UP
        return 'u';

    else if (key=='s') // DOWN
        return 'd';

    else if (key=='d')  // RIGHT
        return 'r';

   else{
        cout << "You have inserted something other than 'a','s','d',w'" << endl;
		cout << "Re-Enter the direction key" << endl;
		char rekey;
		cin >> rekey;
		cin.ignore();
		input(rekey);
	}
};



/*
template <typename T>
void Visual::input(T& inputDir);
void Visual::input(int);*/
