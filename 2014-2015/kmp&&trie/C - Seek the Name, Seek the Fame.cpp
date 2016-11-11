#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define Max 1000001

int rule[Max];
int n;
char s[1000001];

void prekmp()
{
    int i=0,j=rule[0]=-1;
    while (i<n)
    {
        if(j==-1||s[i]==s[j])  {        ++i;++j;rule[i] = s[i] != s[j] ? j:rule[j];}
        else j=rule[j];
    }
}
int main()
{
    while(scanf("%s",&s))
    {
        if(s[0]=='.') break;
        n=strlen(s);
        prekmp();
        int c=1;
        if(n%(n-rule[n])==0) c=n/(n-rule[n]);
        cout<<c<<endl;
    }
    return 0;
}
