#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+1000;
int a[maxn];
int b[maxn];
int c[maxn];
int main()
{
    int maxc,n;
    scanf("%d",&n);
    maxc=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>maxc)
        maxc=a[i];
        int cur=0;
        b[a[i]]++;
        while(a[i]>=1)
        {
            cur++;
            a[i]=a[i]/2;
            b[a[i]]++;
            c[a[i]]+=cur;
        }
    }
    int ans=c[1];
    for(int i=2;i<=maxc;i++)
    {
        if(b[i]==n)
        {
            ans=min(ans,c[i]);
        }
        else if(i%2==0&&b[i/2]==n)
        {
            c[i]=c[i/2]-b[i]+n-b[i];
            b[i]=n;
            ans=min(ans,c[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
