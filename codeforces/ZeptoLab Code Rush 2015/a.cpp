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
#define N 110
char a[N];
int n;
bool flag=true;
int main()
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		for(int j=1;(i+4*j)<=n&&j<=25;j++)
		{
			if(a[i]=='*'&&a[i+j]=='*'&&a[i+2*j]=='*'&&a[i+3*j]=='*'&&a[i+4*j]=='*')
			{
				flag=false;
				break;
			}
		}
	}
	if(flag) cout<<"no";
	else cout<<"yes";
	return 0;
}
