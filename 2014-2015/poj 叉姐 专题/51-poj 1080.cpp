#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define Max 233
using namespace std;
int dp[Max][Max];
char str1[Max],str2[Max];
int len1,len2;
int mp[6][6]={{5,-1,-2,-1,-3},
              {-1,5,-3,-2,-4},
              {-2,-3,5,-2,-2},
              {-1,-2,-2,5,-1},
              {-3,-4,-2,-1,10}};
int f[2333];
int max(int a,int b,int c)
{
    int maxx=a;
    if(maxx<b) maxx=b;
    if(maxx<c) maxx=c;
    return maxx;
}
int main()
{
    int T;
    cin>>T;
    f['A']=0;f['C']=1;f['G']=2;f['T']=3;f['-']=4;
    while(T--)
    {
        cin>>len1;
        scanf("%s",str1);
        cin>>len2;
        scanf("%s",str2);
        dp[0][0]=0;
        for(int i=1;i<=len1;i++)
        {
            dp[i][0]=dp[i-1][0]+mp[f[str1[i-1]]][f['-']];
        }

        for(int j=1;j<=len2;j++)
        {
            dp[0][j]=dp[0][j-1]+mp[f['-']][f[str2[j-1]]];
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                dp[i][j]=max( dp[i-1][j]+mp[ f[str1[i-1] ]][f['-']],dp[i][j-1]+mp[f['-']][ f[str2[j-1] ]],dp[i-1][j-1]+mp[ f[str1[i-1] ]][f[ str2[j-1] ]] );
            }
        }
        cout<<dp[len1][len2]<<endl;

    }
    return 0;
}

