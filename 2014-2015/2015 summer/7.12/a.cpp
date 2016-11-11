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
int T;
int a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		int m,n;
		cin>>m>>n;
		a=0;b=0;int t;
		for(int i=1;i<=m;i++) {cin>>t;a+=t;}
		for(int i=1;i<=n;i++) {cin>>t;b+=t;}
		if(a==b) cout<<"Draw"<<endl;
		else if(a>b) cout<<"Calem"<<endl;\
		else cout<<"Serena"<<endl;
	}
	return 0;
}
