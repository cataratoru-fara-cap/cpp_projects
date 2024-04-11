#include <iostream>
#include<cstring>
using namespace std;

char* getCounty (char *p)
{
    /*
    while(*p!='.')
        p++;
    p++;

    return p;
*/

    p=strtok(p, ".");
    p=strtok(NULL, "/0");
    return p;
}

int main()
{
    char s[]="SLATINA.OT";

    cout<<getCounty(s);
    return 0;
}
