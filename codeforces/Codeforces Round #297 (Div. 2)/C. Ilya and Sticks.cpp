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
#define INF 0x3ffffffff
int n;
int st[100010];
bool flag_1=true;
bool flag_2=true;
long long a=0,b=0;
long long sum=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>st[i];
	sort(st,st+n);
	for(int i=n-1;i>=0;i--)
	{
		if(flag_1)
		{
			if(st[i]-st[i-1]<=1)
			{
				a=st[i-1];
				flag_1=false;
				i--;
			}
		}
		else
		{
			if(st[i]-st[i-1]<=1)
			{
				b=st[i-1];
				flag_2=false;
				i--;
			}
		}
		if(!flag_2)
		{
			sum+=a*b;
			flag_1=true;
			flag_2=true;
		}
	}
	cout<<sum;
	return 0;
}
