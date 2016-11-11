#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define INF 0x3ffffffff
int n;
long a[233333],b[233333],c[233333];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++) cin>>b[i];
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			cout<<a[i]<<endl;
			break;
		}
	}
	for(int i=0;i<n-2;i++)
	{
		cin>>c[i];
	}
	sort(c,c+n,cmp);
	for(int i=0;i<n-1;i++)
	{
		if(b[i]!=c[i])
		{
			cout<<b[i];
			break;
		}
	}
	return 0;
}
