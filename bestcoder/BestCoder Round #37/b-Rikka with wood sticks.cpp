#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int num[1010];
int l[1010];
int n,m;
int tmp,pos,c,tol;
bool flag=false;
int main()
{
	while(cin>>n>>m)
	{
		memset(num,0,sizeof(num));
		memset(l,0,sizeof(l));
		flag=false;
		pos=1;
		tol=0;
		for(int i=1;i<=m;i++)
		{
			cin>>tmp;
			num[tmp]=1;
		}
		if(num[1]==1) pos=0;
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1) {pos++;continue;}
			l[pos]++;
			flag=true;
		}
		if(flag==false) l[pos]=n;
		if(num[n]==1) pos--;
		sort(l+1,l+pos+1);
		c=1;
		for(int i=pos;i>=1&&c<=3;i--)
		{
			c++;
			tol+=l[i];
		}
		c-=1;
		int _case=0;
		if(c==1)
		{
			if(c==4&&c<=2) cout<<"0"<<endl;
			else
			{
				int i=1,j=1,k=1;
				for(i=1,j=i,k=i;i+j+k<=tol;i++)
				{
					for(j=i,k=j;i+j+k<=tol;j++)
					{
						for(k=j;i+j+k<=tol;k++)
						{
							if(i+j+k==tol&&i+j>k) _case++;
						}
					}
				}
			}
			cout<<_case<<endl;
		}
		else if(c==2)
		{
			int maxx=l[pos];
			int minn=l[pos-1];
			for(int i=1;i<=maxx;i++)
			{
				int maxxx=max(i,maxx-i);
				int minnn=min(i,maxx-i);
				if(minnn+minn>maxxx&&maxxx+minnn>minn) _case++;
			}
			cout<<_case<<endl;
		}
		else if(c==3)
		{
			if(l[pos-2]+l[pos-1]>l[pos]) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
		else cout<<"0"<<endl;
	}
	return 0;
}
