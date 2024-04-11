#include <iostream>

using namespace std;

void reverseArray(int *p)
{
    while(*p)
    {
        cout<<*p<<" ";
        p--;
    }
}

int main()
{
    int v[6]={1,2,3,4,5,6};
    reverseArray(&v[5]);
    return 0;
}
