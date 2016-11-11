#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
long long f[233333];
long long ggg[233333];
long long x[233333];
int y=0;

int main()
{
    int m,n,k;long long res=0;

    cin>>m>>n>>k;
    f[0]=0;
    ggg[m+1]=0;long long tmp;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i];
        y++;
        f[i]=f[i-1]|x[i];
    }
    for(int i=m;i>=1;i--)
        ggg[i]=ggg[i+1]|x[i];
        y--;
    for(int i=1;i<=m;i++)
    {
        tmp=x[i];
        for(int j=1;j<=n;j++)
            tmp=(long long)tmp*k;
        res=max(res,f[i-1]|tmp|ggg[i+1]);
    }
    cout<<res;
    return 0;
}
