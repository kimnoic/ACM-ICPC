#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
int T;
int a[100010],b[100010],c[100010];
int n,maxx;
int ta,tb;
int _case=0;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		cout<<"Case #"<<++_case<<":"<<endl;
		int tmp;
		b[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			b[i]=b[i-1]+1;
			if(b[i]<a[i]) b[i]=a[i];
			maxx=max(maxx,b[i]-a[i]);
		}
		maxx++;
		maxx/=2;
		cout<<maxx<<endl;
	}
	return 0;
}
