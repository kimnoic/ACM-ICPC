#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int w,l;
int dp[2333];
char key[2333];
char dic[2333][233];
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    cin>>w>>l;
    scanf("%s",key);
    for(int i=1;i<=w;i++)
    {
        scanf("%s",dic[i]);
    }
    dp[0]=1;
    for(int i=1;i<l;i++)
    {
        dp[i]=dp[i-1]+1;
        int len;int k;
        for(int j=1;j<=w;j++)
        {
            len=strlen(dic[j])-1;
            k=i;
            if(len>i) continue;
            while(len>=0&&k>=0&&k>=len)
            {
                if(key[k]==dic[j][len]) len--;
                k--;
            }
            if(len<0) dp[i]=min(dp[i],dp[k]+i-k-strlen(dic[j]));
        }
    }
    cout<<dp[l-1];
    return 0;
}
