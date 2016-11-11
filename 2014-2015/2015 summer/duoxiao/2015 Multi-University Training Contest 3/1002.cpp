#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000100;
int s[1001000]={0},ss[1001000]={0};
int prime[maxn+1];
void getprime()
{
    memset(prime, 0, sizeof(prime));
    for (int i=2;i<=maxn;i++)
    {
        if (!prime[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}

int fatcnt;
int getfactors(int x)
{
    fatcnt=0;
    int tmp=x;
    for (int i=1;prime[i]<=tmp/prime[i];i++)
    {
        if (tmp%prime[i]==0)
        {
            while (tmp%prime[i]==0)
                tmp/=prime[i];
            fatcnt++;
        }
    }
    if (tmp!=1) fatcnt++;
    return fatcnt;
}

inline int lowbit(int x) {
    return x & (-x);
}

int MAX(int a,int b)
{
    if (a>b) return a;
    else return b;
}
void Init(int n){
    for(int i=1;i<=n;i++){
        ss[i]=s[i];
        for(int j=1;j<lowbit(i);j<<=1){
            ss[i]=MAX(ss[i],ss[i-j]);
        }
    }
}


int Query(int l,int r){
    int ans=s[r];
    while(true){
        ans=MAX(ans,s[r]);
        if(r==l) break;
        for(r-=1;r-l>=lowbit(r);r-=lowbit(r)){
            ans=MAX(ans,ss[r]);
        }
    }
    return ans;
}

int main()
{
    int i,j,m,n,k,x,y;
    getprime();
    for (i=2;i<=1000010;i++)
        s[i]=getfactors(i);
    int T;
    s[1]=ss[1]=0;
    Init(1000000);
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",Query(x,y));
    }
    return 0;
}
