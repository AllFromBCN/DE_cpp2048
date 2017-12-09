#include <iostream>
#include "block.h"
<<<<<<< HEAD
using namespace std;

int main() {
    Block b1(1,2,4, false);
    std::cout << b1.getBonus() << std::endl;
    return 0;
}
=======
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
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
