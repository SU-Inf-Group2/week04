#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    while(true)
    {
        int h = 0, m = 0;
        cin >> h >> m;
        Time now(h, m);
        now.print();
    }
}
