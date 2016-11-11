#include <cstdio>
using namespace std;
int a[100005];
int main()
{
    int cost=0,i,j,m,n,k,power=0;
    scanf("%d",&n);
    a[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        k=a[i-1]-a[i];
        if (power+k>=0) power+=k;else
        {
            cost+=-(k+power);
            power=0;
            a[i-1]+=-(k+power);
        }
    }
    printf("%d\n",cost);
    return 0;
}
