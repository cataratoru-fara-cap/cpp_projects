#include <iostream>

using namespace std;

void displayArray(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout<<*(a+i)<<" ";

    cout<<endl;
}

int main()
{
    int v[6]={1,2,3,4,5,6};
    displayArray(v,6);
    return 0;
}
