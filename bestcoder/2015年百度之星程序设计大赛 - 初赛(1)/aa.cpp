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
int T,_case=0,n,k,m;
struct pt
{
	long long num;
	int flag;
}p[10010];
bool cmp(struct pt a,struct pt b)
{
	return a.num<b.num;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) p[i].flag=0;
		for(int i=1;i<=n;i++) scanf("%I64Dd",&p[i].num);
		cout<<"Case #"<<++_case<<":"<<endl;
		sort(p+1,p+n+1,cmp);
		int f=1;
		int i=1;
		//for(int i=1;i<=n;i++) cout<<p[i].num<<endl;
		while(p[i].num<=m) i++;
		int y=1;
        if(i!=1) i--;
        else if(i==1)
		{
			if(p[1].num-m>k) y=0;
			else k--;
		}
		if(y==1)
        for(;i<n;i+=f)
		{
			f=1;
			if(p[i].num+k>=p[i+1].num)
			{
				//cout<<p[i].num<<" "<<k<<" "<<p[i+1].num<<endl;
				while(i+f<=n&&p[i+f].num-p[i].num<=k)
			{
				f++;
			}
			f--;
			if(k>0) k--;}
			else break;
		}

		if(i>=n&&y==1) cout<<"why am I so diao?"<<endl;
		else cout<<"madan!"<<endl;
	}
	return 0;
}
