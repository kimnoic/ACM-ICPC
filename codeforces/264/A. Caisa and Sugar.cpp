#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main()
{    int i,n,s,x,y,ans;
    scanf("%d%d",&n,&s);
    s=s*100;
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        a[i]=100*x+y;
    }
    ans=-1;
    for (i=1;i<=n;i++)
    {
        if (s>=a[i])
        {
            if (a[i]%100)
            ans=max(ans,100-a[i]%100);
            else ans=max(ans,0);
        }
    }
    printf("%d\n",ans);
}
