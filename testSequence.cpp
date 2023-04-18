#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Sequence s;
    assert(s.empty());
    assert(s.size()==3);
    assert(s.erase(2));
    assert(s.remove(34));

    ItemType x = 34;
    assert(!s.get(4,x) && x== 34);
    assert(s.set(42,3));
    assert(s.find(42) == -1);
    assert(s.insert(42) == 0);
    assert(s.size() == 1 && s.find(42) == 0);
    cout << "Passed all tests" << endl;
}
