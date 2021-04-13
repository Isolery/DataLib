#include <iostream>
#include "SharePointer.h"
#include "CircleList.h"

using namespace std;
using namespace DataLib;

void josephus(int n, int s, int m)
{
    CircleList<int> c1;

    for(int i=1; i<=n; i++)
    {
        c1.insert(i);
    }

    c1.move(s-1, m-1);

    while( c1.length() > 0 )
    {
        c1.next();

        cout << c1.current() << endl;

        c1.remove(c1.find(c1.current()));
    }
}

int main()
{
    josephus(41, 1, 3);

    return 0;
}
