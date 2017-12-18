#include "visual.h"
#include <string>

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
	string key;
	while (1)
	{
		v.show(ori_map);
		cout << endl;
		
		if (ori_map.countEmpty() == 0 && ori_map.check() == 0)
		{
			cout << "Game Over!" << endl;
			//cin >> key;
			return 0;
		}

		cout << "Enter the direction key" << endl;
		cin >> key;

		while (key != "a" && key != "s" && key != "w" && key != "d")
		{
			cout << "You have inserted something other than 'a','s','d',w'" << endl;
			cout << "Re-Enter the direction key" << endl;
			cin >> key;
			if (key == "a" || key == "s" || key == "w" || key == "d")
				break;
		}

		if (ori_map.countEmpty() == 0)
		{
			if (ori_map.check() == 2 && (key == "w" || key == "s"))
			{
				cout << "Not move! You Re-Enter the direction key" << endl;
				continue;
			}
			else if (ori_map.check() == 3 && (key == "a" || key == "d"))
			{
				cout << "Not move! You Re-Enter the direction key" << endl;
				continue;
			}
		}
		ori_map.move(v.input(key));
		ori_map.operator+();
	}
	return 0;
}
