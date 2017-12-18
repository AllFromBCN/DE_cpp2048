#include "visual.h"
using namespace std;

int main()
{
	Visual v;
	string enter;
	Map ori_map;
	int i;
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
				ori_map.setSize(4);
				ori_map.operator+(2);
				ori_map.operator+(2);
				break;
			}
			else if (enter >= "5"&& enter <= "9")
			{
				ori_map.setSize(stoi(enter));
				ori_map.operator+(2);
				ori_map.operator+(2);
				break;
			}
			else
				throw enter;
		}
		catch (string exception) {
			cout << "You entered the " << exception << "." << endl;
			cout << "Out of range. Please re-enter" << endl;
		}
	}
	char key;
	while (1)
	{
		v.show(ori_map);
		cout << endl;
		cout << "Enter the direction key" << endl;
        cin >> key;
		ori_map.move(v.input(key));//입력키 받는부분

		if (ori_map.countEmpty() == 0 && ori_map.check() == false)
		{
			cout << "Game Over!" << endl;
			return 0;
		}
	}
	return 0;
}
