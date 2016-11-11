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

int main()
{
	int n,a[1005],i,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	r=n-a[0];
	for(i=1;i<n;i++)
	{
		if(i%2==1)
		{
			a[i]=a[i]-r;
		}
		else
		{
			a[i]+=r;
		}
		a[i]+=n;
		a[i]%=n;
		if(a[i]!=i)
		{
			break;
		}
	}
	if(i==n)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
