#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        map<string ,int >s;
        string s1,s2;
        for(int i=1;i<=n;i++)
        {
            cin>>s1>>s2;
            if(!s[s1]) s[s1]=0;
            s[s2]=1;
        }
        int cnt=0;
        map<string,int>::iterator it;
        for(it=s.begin();it!=s.end();++it)
            {if(it->second==0) cnt++;}
        if(cnt!=1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
