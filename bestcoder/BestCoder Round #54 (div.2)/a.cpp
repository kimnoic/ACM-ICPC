#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct self
{
    string str;
    int age;
}s[1111];
int cmp(self a1,self a2)
{
    return a1.age>a2.age;
}
int m,T,n;
string str;
int len;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            while(1)
            {
                getline(cin,str);
                if(str!="" && str!="\n")
                    break;
            }
            len=str.length();
            int age=0;
            for(int j=len-4;j<len;j++)
                age=age*10+str[j]-'0';

            s[i].age=age;
            s[i].str=str.substr(0,len-4-1);
        }
        sort(s+1,s+m+1,cmp);
        for(int i=1;i<=m;i++)cout<<s[i].str<<endl;
    }
    return 0;
}
