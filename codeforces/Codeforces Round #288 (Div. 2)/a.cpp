#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <time.h>
int n,m,k;
int a[1010][1010];
int x,y;
bool check()
{
	if(a[x-1][y]==1&&a[x-1][y-1]==1&&a[x][y-1]==1) return true;
	else if(a[x][y-1]==1&&a[x+1][y]==1&&a[x+1][y-1]==1) return true;
	else if(a[x][y+1]==1&&a[x-1][y]==1&&a[x-1][y+1]==1) return true;
	else if(a[x][y+1]==1&&a[x+1][y]==1&&a[x+1][y+1]==1) return true;
	else return false;
}
using namespace std;
int main()
{
	cin>>n>>m>>k;
	memset(a,0,sizeof(a));
	int t=0;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		if(check()) {t=i;break;}
	}
	cout<<t;
	return 0;
}
