#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int Gcd(int a,int b)
{
    return b==0?a:Gcd(b,a%b);
}

int f[3000005];
int stone[105];
bool vis[3000005];

int main()
{
    int L,S,T,M;
    scanf("%d%d%d%d",&L,&S,&T,&M);
    int i,j,lcm,ans;
    for(i=1;i<=M;i++)
        scanf("%d",&stone[i]);

    lcm=2520;
    sort(stone+1,stone+M+1);
    stone[M+1]=L;
    for(int i=1;i<=M;++i)
    {
                stone[i+1]=stone[i]+(stone[i+1]-stone[i])%lcm;
    }
    L=stone[M+1];
    for(i=1;i<=M;++i)
        vis[stone[i]]=1;
    f[0]=0;
    for(i=1;i<=L+T;++i)
    {
        f[i]=M;
        for(j=S;j<=T;++j)
                if(i>=j && f[i]>f[i-j]+vis[i])
                        f[i]=f[i-j]+vis[i];
    }
    ans=M;
    for(i=L;i<=L+T;++i)
        if(ans>f[i])
            ans=f[i];

    printf("%d\n",ans);
    return 0;
}
