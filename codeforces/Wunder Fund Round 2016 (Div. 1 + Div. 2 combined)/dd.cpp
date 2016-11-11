#include<bits/stdc++.h>
using namespace std;

int m,n;
int d[222222];
int x,y;
int l,r;
struct self
{
    int x,y;
}s[222222];
int ge;

long long ans;

int zz()
{
    for(int i=1;i<=m;i++)
        if(d[i]==m-1)
            return 1;
    return 0;
}
int main()
{
    scanf("%d%d%d",&m,&x,&y);
    for(int i=1;i<m;i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
        d[s[i].x]++;
        d[s[i].y]++;
    }
    for(int i=1;i<=m;i++)
        if(d[i]==1)
            ge++;

    if(x<y)
    {
        long long need=(ge-1)/2;
        ans=(long long)need*y + (long long)(m-1-need)*x;
    }
    else
    {
        if(zz())
            ans=(long long)(m-2)*y+(long long)x;
        else
            ans=(long long)(m-1)*y;
    }
    cout<<ans<<endl;
    return 0;
}
