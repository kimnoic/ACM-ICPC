#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define N 100007
#define Max 520
#define Min 25

int main()
{
    int t,casew=1;
    int n,k,we;
    double ans=0;
    cin>>t;
    double b[Max],dp[Min],a[Min],c,d;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=k;i++) cin>>a[i];
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            cin>>we;
            for(int j=1;j<=we;j++)
            {
                cin>>c>>d;
                b[i]+=c*d;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i>=j+1)
                    dp[i]+=dp[i-j]*a[j];
            }
        }
        for(int i=1;i<=n;i++) ans+= dp[i]*b[i];
        printf("Case #%d: %.6lf\n",casew++,ans);
        ans=0;
    }
    return 0;
}
