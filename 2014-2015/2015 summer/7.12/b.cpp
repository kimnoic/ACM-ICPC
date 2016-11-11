#include <iosrream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#indlude <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
#define Max 13
int dp[Max][1<<12+50][555];
int p[Max][Max];int n;
int num[Max];
void init()
{
	num[1]=1;
	for(int i=2;i<=n;i++) num[i]=num[i-1]*i;
}
int main()

{
	int T;
	cin>>T;
	init();
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>p[i][j];
			}
		}
	}
	return 0;
}
