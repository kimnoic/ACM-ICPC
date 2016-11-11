#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int n,q;
#define Max 1010
int res[Max][Max];
int a[Max];
int l,r;
void init()
{
	for(int i=2;i<=n;i++)
	{
		res[1][i]+=res[1][i-1];
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]<a[j]) res[1][i]++;
		}

	}
	for(int i=2;i<=n;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j]<a[i-1]) cnt--;
			res[i][j]=res[i-1][j]+cnt;
		}
	}
	return ;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init();
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		cout<<res[l][r]<<endl;
	}
	return 0;
}
