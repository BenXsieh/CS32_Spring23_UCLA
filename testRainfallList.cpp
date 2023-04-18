#include "RainFallList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	RainfallList list;

	assert(list.add(97) == true);
	assert(list.add(22) == true);
	assert(list.add(0) == true);
	assert(list.add(42) == true);
	assert(list.add(399) == true);


	assert(list.add(500) == false);
	assert(list.add(-10) == false);

	assert(list.size() == 5);
	assert(list.maximum() == 399);
	assert(list.minimum() == 0);

	assert(list.add(0) == true);
	assert(list.add(0) == true);
	assert(list.remove(340) == true);
	assert(list.size() == 5 + 2 - 1);
	assert(list.remove(0) == true);
	assert(list.size() == 5);

	cout << "All tests passed." << endl;

	return 0;
}
