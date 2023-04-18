#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	Sequence s;
	assert(s.empty());
	assert(s.find(42) == -1);
	assert(s.insert(42) == 0);
	assert(s.size() == 1 && s.find(42) == 0);
	assert(s.insert(24) == 0);
	assert(s.insert(52) == 2);
	assert(s.insert(52) == 2);

	assert(s.erase(0));
	assert(s.size() == 3);
	assert(s.remove(52));
	assert(s.size() == 1);

	Sequence b(3);
	assert(b.empty());
	assert(b.find(42) == -1);
	assert(b.insert(42) == 0);
	assert(b.size() == 1 && b.find(42) == 0);
	assert(b.insert(24) == 0);
	assert(b.insert(52) == 2);
	assert(b.insert(52) == -1);

	assert(b.erase(0));
	assert(b.size() == 2);
	assert(b.remove(52));
	assert(b.size() == 1);

	Sequence a(1000);   
	Sequence b(5);     
	Sequence c;        
	ItemType v = 69;

	for (int k = 0; k < 5; k++)
		assert(b.insert(v) != -1);

	assert(b.insert(v) == -1);

	
	a.swap(b);
	assert(a.insert(v) == -1 && b.insert(v) != -1);

	cout << "Passed all tests" << endl;

	return 0;
}
