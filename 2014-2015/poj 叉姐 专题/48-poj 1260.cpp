#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define Max 1024
int T,p[Max],a[Max],n,sum[Max],dp[Max];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>p[i];
            sum[i]=sum[i-1]+a[i];
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(a[i]+10)*p[i]+dp[i-1];
            for(int j=0;j<i;j++)
            {
                dp[i]=min(dp[i],(sum[i]-sum[j]+10)*p[i]+dp[j]);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
