#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 233
int dp[Max][Max];int p[Max];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n-2;i++)
        dp[i][i+2]=p[i]*p[i+1]*p[i+2];
    for(int i=3;i<=n;i++)
    {
        for(int j=1;i+j<=n;j++)
        {
            for(int k=j+1;k<i+j;k++)
            {
                if(dp[j][i+j]==0) dp[j][i+j]=dp[j][k]+dp[k][i+j]+p[j]*p[k]*p[i+j];
                else dp[j][i+j]=min(dp[j][i+j],dp[j][k]+dp[k][i+j]+p[k]*p[j]*p[i+j]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
