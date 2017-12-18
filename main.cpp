#include "visual.h"
using namespace std;

int main()
{
	Visual v;
	string enter;
	Map ori_map;
	int i;
	cout << "You make the 2048 tile!" << endl;
	cout << "You can use the a w d s button" << endl;
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
            return 0;
        }

		cout << "Enter the direction key" << endl;
        cin >> key;

        while(key != "a" && key != "s" && key != "w" && key != "d")
        {
            cout << "Please enter another direction key" << endl;
            cin >> key;
            if (key == "a" || key == "s" || key == "w" || key == "d")
                break;
        }

        if(!ori_map.countEmpty())
        {
            if(ori_map.check()==2 && (key == "w" || key == "s"))
            {
                cout << "Game Over!" << endl;
                return 0;
            }
            else if(ori_map.check()==3 && (key == "a" || key == "d"))
            {
                cout << "Game Over!" << endl;
                return 0;
            }
        }

		ori_map.move(v.input(key));//입력키 받는부분
        ori_map.operator+();



	}
}
