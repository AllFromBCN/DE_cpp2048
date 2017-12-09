/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/
#include "map.h"
#include <iostream>
#include <string>

using namespace std;

class Visual : public Map{
public:
	Visual(){}
	
	~Visual(){}
	
	void show()
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
				int num = map[i][j]; //@가 없는 map만 실행됨.. @을 제거하는 방법을 찾아야함 
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
				/*if(map[i][j].find('@')) // 왜 찾아지지? 그래서 차라리 map을 int로만 만들고, bonus인지를 따로 체크하는 array만드는것은? 
				{
					temp[k] = '@';
				}*/
				
				cout<<temp;
			}
			cout << endl;
		}
	}
};

Visual start(Visual map)
{
	string enter;
	cout << "You make the 2048 tile!" << endl;
	cout << "You can use the ←↑→↓ or A W D S butten" << endl;
	cout << "If you want to start with 4x4 map, then enter the 's'" << endl;
	cout << "If you want to start with a map larger then 4X4, then enter the number between 5 and 9" << endl;
	while(1)
	{
		getline(cin, enter);
		try{
			if(enter == "s")
			{
				map.make_map(4);
				break;
			}
			else if(enter >= "5"&& enter <= "9")
			{
				map.make_map(stoi(enter));
				break;
			}
			else
				throw enter;
		}
		catch (string exception){
			cout << "You enter the " << exception << endl;
			cout << "Out of range. Please re-enter" << endl;
		}
	}
	return map;
}

int main()
{
	Visual map;
	map = start(map);
	map.show();
	
}
