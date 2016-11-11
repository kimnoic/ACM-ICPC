#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
int T;
long long k,b,x,p,res;
int main()
{
    scanf("%d",&T);
    map<long long,bool>mp;
    while(T--)
    {
        mp.clear();map<long long,bool>mp;
        scanf("%I64d %I64d %I64d %I64d",&k,&b,&x,&p);
        long long n=x;
        int i;res=0;
        for(i=1;i<=p;i++)
        {
            n*=k;
            n+=b;
            n%=p;
            if(!mp[n]) mp[n]=true;
            else break;
            if(n==x)
            {
                res=i;
                break;
            }
        }
        if(res==i) printf("%I64d\n",res);
        else printf("-1\n");
    }
    return 0;
}
