#include <bits/stdc++.h>
using namespace std;
struct tr
{
	int x,p;
}tree[2333];
int n;
bool cmp(tr a,tr b)
{
	return a.x<b.x;
}
int main()
{
	cin>>n;
	int max=100000;
	for(int i=1;i<=n;i++)
	{
		cin>>tree[i].x>>tree[i].p;
		if(tree[i].x>=0&&tree[i].x<max)
		{
			max=tree[i].x;
		}
	}
	int pos;
	sort(tree+1,tree+n+1,cmp);
	if(max==100000) pos=n+1;
	for(int i=1;i<=n;i++)
	{
		if(tree[i].x==max)
		{
			pos=i;
			break;
		}
	}
	int flag=1;
	int l=pos-1;
	int r=n-pos+1;
	int sum=0;
    if(l>r)
	{
		int pp=1;
		while(pp<=2*r+1)
		{
			sum+=tree[n].p;
			n--;
			pp++;
		}
	}
	else
	{
		int pp=1;
		while(pp<=2*l+1)
		{
			sum+=tree[pp].p;
			pp++;
		}
	}

	cout<<sum;
	return 0;
}
