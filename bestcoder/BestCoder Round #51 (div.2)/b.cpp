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
const int lim=3*1000321;
int f[lim];
int flag[lim];
int cd[lim];
long long big;
const long long mod = 3221225473L;
int m,n,t;

int dfs(int i)
{
    flag[i]=1;
    int u = f[i];
    if(!flag[u])
        return 1+dfs(u);
    else
        return 1;
}

int main()
{
    cin>>t;
    int y=0;
    while(t--)
    {
        memset(flag,0,sizeof(flag));
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&n);
            f[n]=i;
        }
        n=0;
        for(int i=1;i<=m;i++)
            if(!flag[i])
            {
                n++;
                cd[n]=dfs(i);
            }
        big=1;
        y++;
        long long temp;
        for(int i=1;i<=n;i++)
        {
            temp=cd[i];
            big=((long long)big*temp/__gcd(big,temp) % mod);
        }
        //printf("%d\n",big)
        if(big==1) cout<<0<<endl;
        else
        cout<<big<<endl;
    }
    return 0;
}
