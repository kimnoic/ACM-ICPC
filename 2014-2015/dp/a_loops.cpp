#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 1001
using namespace std;

double abs(double a)
{
    if(a>0) return a;
    else return -a;
}

double dp[N][N];
double table[N][N][3];

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=a;i++)
            {
                for(int j=1;j<=b;j++)
                {
                    for(int k=0;k<3;k++)
                    {
                        cin>>table[i][j][k];
                    }
                }
            }
        for(int i=a;i>0;i--)
        {
            for(int j=b;j>0;j--)
            {
                if(i==a&&j==b&&abs(1-table[i][j][0])<1e-7)
                    continue;
                double k=table[i][j][1]*dp[i][j+1]+table[i][j][2]*dp[i+1][j]+2;
                dp[i][j] = k/(1-table[i][j][0]);
            }
        }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}
