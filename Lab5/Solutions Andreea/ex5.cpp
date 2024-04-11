#include <iostream>
#include<cstring>
using namespace std;

void replaceSemicolon (char *p)
{
    for(int i=0; i<strlen(p); i++)
        if(*(p+i)==';')
            *(p+i)=32;

}

int main()
{
    char s[]="College;of;London;";
    replaceSemicolon(s);
    cout<<s;
    return 0;
}
