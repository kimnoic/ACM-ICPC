#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,j,m,n,k,t;
    int a[105]={0};
    scanf("%d%d",&n,&k);
    int mi=1e9;
    int ma=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]<mi) mi=a[i];
        if (a[i]>ma) ma=a[i];
    }
    if (ma-mi<=k)
    {
    printf("YES\n");
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=mi;j++)
            if (j!=a[i]) printf("1 ");else printf("1\n");
        for (j=mi+1;j<=a[i];j++)
        if (j!=a[i]) printf("%d ",j-mi);else printf("%d\n",j-mi);
    }
    } else
    printf("NO\n");
    return 0;
}
