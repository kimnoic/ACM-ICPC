#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 40010
int n,m;
int a[Max];
int main()
{
	int T;
	cin>>T;
	int max=0;
	while(T--)
	{
		max=0;
		cin>>n>>m;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(max<a[i]) max=a[i];
		}
		sort(a+1,a+n+1);
		int res=sum/m;
		if(sum%m!=0) res++;
		if(res<max) res=max;
		cout<<res<<endl;
	}
	return 0;
}
