#include "block.h"
#include "score.h"
#include "map.h"
#include "visual.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Visual v;
	string enter;
	Map m;
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
				m.setMap(4);
				break;
			}
			else if (enter >= "5"&& enter <= "9")
			{
				m.setMap(stoi(enter));
				break;
			}
			else
				throw enter;
		}
		catch (string exception) {
			cout << "You entered the " << exception << "." << endl;
			cerr << "Out of range. Please re-enter" << endl;
		}
	}
	v.show(m);
	cin >> i;

	return 0;
}
