#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 233
char s[Max];
int main()
{
    while(scanf("%s",s))
    {
        if(s[0]=='*') break;
        int len=strlen(s);
        if(len<=2) {cout<<s<<" is surprising."<<endl;continue;}
        int flag=0;
        for(int i=1;i<=len-2;i++)
        {
            map<string , bool > f;
            for(int j=0;j+i<len;j++)
            {
                char t[3]={s[j],s[j+i],'\0'};
                if(f[t])
                {
                    flag=1;
                    break;
                }
                else f[t]=true;
            }
        }
        if(!flag) cout<<s<<" is surprising."<<endl;
        else cout<<s<<" is NOT surprising."<<endl;
    }
    return 0;
}
