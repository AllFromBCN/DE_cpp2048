/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/
//#include "map.h"
#include <iostream>
#include <string>

using namespace std;

string map[4][4] = {"@2","8", "0", "0" ,"0", "@4", "8", "0", "@2", "4", "8", "16", "0", "0", "0", "0"};

class Visual{
public:
	Visual(){}
	
	~Visual(){}
	
	void show(int score, int size)
	{
		cout << "Score : " << score << endl;
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				char temp[5];
				for(int k=0; k<4; k++)
				{
					temp[k] = '_';
				}
				temp[4] = ' ';
				int num = stoi(map[i][j]); //@가 없는 map만 실행됨.. @을 제거하는 방법을 찾아야함 
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
				if(map[i][j].find('@'))
				{
					temp[k] = '@';
				}
				
				cout<<temp;
			}
			cout << endl;
		}
	}
};


int main()
{
	Visual v;
	cout << stoi(map[0][0])<< endl;
	//v.show(100, 4);
}
