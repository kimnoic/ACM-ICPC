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
#define Max 100010
int n;
int a[Max],c[Max];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cur=1,temp=a[1];
	int max=0;
	int pos;
	if(c[cur]>max)
	{
		max=c[cur];
		pos=cur;
	}
	for(int i=2;i<=n;i++)
	{
		if(temp<a[i])
		{
			c[cur]++;
			c[i]++;
		}
		else
		{
			c[cur]++;
			c[i]++;
			cur=i;
			temp=a[i];
		}
		if(c[cur]>max)
		{
			max=c[cur];
			pos=cur;
		}
	}
	cout<<pos;
	return 0;
}
