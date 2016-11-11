#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long LL;

LL fac[20];
map<LL, LL> mp[30];
LL num[30];
int n, k;
LL ans, s;

void dfs_1(int i, int cnt, LL sum)
{
    if (sum > s || cnt > k)
    {
        return;
    }
    if (i == n / 2)
    {
        ++mp[cnt][sum];
        return;
    }
    dfs_1(i + 1, cnt, sum);
    dfs_1(i + 1, cnt, sum + num[i]);
    if (num[i] <= 18)
    {
        dfs_1(i + 1, cnt + 1, sum + fac[num[i]]);
    }
}
/*
void dfs_2(int i, int cnt, LL sum)
{
    if (sum > s || cnt > k)
    {
        return;
    }
    if (i == n)
    {
        for (int j = 0; j + cnt <= k; ++j)
        {
            if (mp[j].count(s - sum))
            {
                ans += mp[j][s - sum];
            }
        }
        return;
    }
    dfs_2(i + 1, cnt, sum);
    dfs_2(i + 1, cnt, sum + num[i]);
    if (num[i] <= 18)
    {
        dfs_2(i + 1, cnt + 1, sum + fac[num[i]]);
    }
}
*/
void dfs_2(int a,int cnt,long long sum)
{
	if(cnt>k||sum>s) return ;
	if(a==n)
	{
		for(int i=0;i+cnt<=k;i++)
		{
			if(mp[i].count(s-sum))
			{
				ans+=mp[i][s-sum];
			}
		}
		return ;
	}
	dfs_2(a+1,cnt,sum);
	dfs_2(a+1,cnt,sum+num[a]);
	if(num[a]<=18)
	{
		dfs_2(a+1,cnt+1,sum+fac[num[a]]);
	}
}
int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 18; ++i)
    {
        fac[i] = fac[i - 1] * i;
    }
    scanf("%d%d%lld", &n, &k, &s);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &num[i]);
    }
    dfs_1(0, 0, 0);
    ans = 0;
    dfs_2(n / 2, 0, 0);
    printf("%lld\n", ans);
    return 0;
}
