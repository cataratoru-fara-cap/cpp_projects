#include <iostream>

using namespace std;

void replaceArray(int *p, int n)
{
    for(int i=0; i<n/2; i++)
    {
        int aux = *(p+i);
        *(p+i) = *(p+n -i-1);
        *(p+n -i-1) = aux;
    }
}
void displayArray(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout<<*(a+i)<<" ";

    cout<<endl;
}
int main()
{
    int v[6]={1,2,3,4,5,6};
    replaceArray(v,6);
    displayArray(v,6);
    return 0;
}
