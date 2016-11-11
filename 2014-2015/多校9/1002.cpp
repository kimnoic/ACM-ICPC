#include <cstdio>
#include <iostream>
#include <cstring>
#include <math.h>
#define N 100005
using namespace std;
long long sum;
int f[N], g[N];
int a[N], b[N],c[N];
int i,j;
int k[N]={};
void work(int a)
{
    for(int u=1;u<=sqrt(a);u++)
    {
        if(a%u==0)
        {
            k[u]=1;
            k[a/u]=1;
        }
    }
}
int main()
{
    int n;
    while (scanf("%d",&n) && n)
    {
        memset(k,0,sizeof(k));
        for(int i=1;i<=n;i++) {f[i]=i;g[i]=i;}
        for (i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            work(a[i]);
            if(k[a[i]]==1)
        for ( j=i-1; j>=1; j--)
            {
                if (a[j]>=a[i] && a[j]%a[i]==0) {f[i]=j;break;}
            }
            b[i]=a[f[i]];
        }
         sum=0;
         memset(k,0,sizeof(k));
        for(int i=n;i>=1;i--)
        {
            work(a[i]);
            if(k[a[i]]==1)
            for ( j=i+1; j<=n; j++)
            {
                if (a[j]>=a[i] && a[j]%a[i]==0) {g[i]=j;break;}
            }
            c[i]=a[g[i]];
            sum+=b[i]*c[i];
        }
        printf("%lld\n", sum);
       }
    return 0;
}
