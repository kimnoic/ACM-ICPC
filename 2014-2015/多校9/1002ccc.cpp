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
void work(int y)
{
    for(int u=1;u<=sqrt(a[y]);u++)
    {
        if(a[y]%u==0)
        {
            k[u]=y;
            k[a[y]/u]=y;
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
            work(i);
            if(k[a[i]]!=0)
        /*for ( j=i-1; j>=1; j--)
            {
                if (a[j]>=a[i] && a[j]%a[i]==0) {f[i]=j;break;}
            }
        }*/
        f[i]=k[a[i]];
         sum=0;
         memset(k,0,sizeof(k));
        for ( i=n; i>=1; i--)
        {
            b[i]=a[f[i]];
            work(i);
            if(k[a[i]]!=0)
            /*for ( j=i+1; j<=n; j++)
            {
                if (a[j]>=a[i] && a[j]%a[i]==0) {g[i]=j;break;}
            }*/
            g[i]=k[a[i]];
            c[i]=a[g[i]];
            sum+=b[i]*c[i];
        }
    }

        printf("%lld\n", sum);
       }
    return 0;
}
