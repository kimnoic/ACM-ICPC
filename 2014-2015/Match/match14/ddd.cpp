#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MIN 30
#define MAX 520


int main()
{
    int t,_case = 1;
    int n,k,we;
    cin>>t;
    double b[MAX], dp[MAX],a[MIN];
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=k;i++)cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&we);
            b[i]=0;
            for(int j=1;j<=we;j++)
            {
                double d,f;
                cin>>d>>f;
                b[i]+=d*f;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i>=j+1)
                    dp[i] += dp[i-j]*a[j];
            }
        }
        double ans = 0;
        for(int i=1;i<=n;i++)
           ans+= dp[i]*b[i];
        printf("Case #%d: %.6lf\n",_case++,ans);
    }
    return 0;
}
