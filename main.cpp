#include "visual.h"
#include <string>

using namespace std;

template <typename T>
void generateMap(T mapSize, Map &ori_map) // int
{
	ori_map.setSize(mapSize);
	ori_map.operator+(2);
	ori_map.operator+(2);
}

template <>
void generateMap<string>(string mapSize, Map &ori_map)
{
	int mapSizeInt;
	if (mapSize == "s")
		mapSizeInt = 4;
	else
		throw mapSize;

	ori_map.setSize(mapSizeInt);
	ori_map.operator+(2);
	ori_map.operator+(2);
}

int main()
{
	Visual v;
	string enter;
	Map ori_map;

	cout << "You make the 2048 tile!" << endl;
	cout << "You can use the 'a, w, d, s' button" << endl;
	cout << "If you want to start with 4x4 map, then enter the 's'" << endl;
	cout << "If you want to start with a map larger then 4X4, then enter the number between 5 and 9" << endl;
	while (1)
	{
		int enterInt;
		getline(cin, enter);
		try {
			if (enter >= "4" && enter <= "9")
			{
				enterInt = stoi(enter);
				generateMap(enterInt, ori_map);
			}
			else
				generateMap(enter, ori_map);

			break;
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
				cout << "Not move! You Re-Enter the direction key\n" << endl;
				continue;
			}
			else if (ori_map.check() == 3 && (key == "a" || key == "d"))
			{
				cout << "Not move! You Re-Enter the direction key\n" << endl;
				continue;
			}
		}
		try
		{
			ori_map.move(v.input(key));
		}
		catch (int exception)
		{
			cout << "Not move! You Re-Enter the direction key\n" << endl;
			continue;
		}
		catch (char exception)
		{
			cout << "Sorry! Numbers with more than 4 digits can not be printed." << endl;
			cout << "Congratulations! Game is finish" << endl;
			cin >> key;
			return 0;
		}
		ori_map.operator+();
	}
	return 0;
}
