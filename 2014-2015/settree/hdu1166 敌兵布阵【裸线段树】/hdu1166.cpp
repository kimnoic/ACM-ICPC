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
#define Max 50010
struct line
{
	int r,l,sum;
}tree[Max*4];
int n;
int val[Max];
char s[10];
int rr,ll;
int pos,va;

int build(int l,int r,int p)
{
	int mid;
	if(l==r)
	{
		tree[p].l=tree[p].r=l;
		return tree[p].sum=val[l];
	}
	mid=(l+r)/2;
	tree[p].l=l;
	tree[p].r=r;
	return (tree[p].sum=build(l,mid,2*p)+build(mid+1,r,2*p+1));
}
void add(int l,int r,int p)
{
	if(l==r&&l==pos)
	{
		tree[p].sum+=va;return ;
	}
	int mid=(r+l)/2;
	tree[p].sum+=va;
	if(pos<=mid)
	{
		add(l,mid,p*2);
	}
	else
	{
		add(mid+1,r,p*2+1);
	}
}
int query(int l,int r,int p)
{
	int mid;
	if(tree[p].l==l&&tree[p].r==r)
		return tree[p].sum;
	mid=(tree[p].l+tree[p].r)/2;
	if(r<=mid) return query(l,r,p*2);
	else if(l>mid) return query(l,r,p*2+1);
	else return query(l,mid,p*2)+query(mid+1,r,p*2+1);
}
int main()
{
	int _case;
	cin>>_case;
	int y=0;
	while(_case--)
	{
		cout<<"Case "<<++y<<":"<<endl;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>val[i];
		build(1,n,1);
		while(1)
		{
			cin>>s;
			if(s[0]=='E') break;
			else if(s[0]=='A')
			{
				cin>>pos>>va;
				add(1,n,1);
			}
			else if(s[0]=='Q')
			{
				cin>>ll>>rr;
				cout<<query(ll,rr,1)<<endl;
			}
			else
			{
				cin>>pos>>va;
				va=-va;
				add(1,n,1);
			}
		}
	}
	return 0;
}
