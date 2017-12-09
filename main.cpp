#include <iostream>
#include "block.h"
using namespace std;

int main() {
    Block b1(1,2,4, false);
    std::cout << b1.getBonus() << std::endl;
    return 0;
}