#include <iostream>
#include "block.h"
#include "map.h"

using namespace std;

int main()
{
	Map m(4);
	cout << m.map[1][1].col << endl;

	int in;
	cin >> in;

	return 0;
}
