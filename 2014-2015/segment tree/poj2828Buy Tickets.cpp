#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define Max 200100
int n,pos[Max],w[Max],tree[Max<<2],res[Max],cnt;
void build(int l,int r,int k)
{
	tree[k]=r-l+1;
	if(l==r) return ;
	int m=(l+r)/2;
	build(l,m,k*2);
	build(m+1,r,k*2+1);
}
int update(int l,int r,int k,int p)
{
	int m=(l+r)/2;
	tree[k]--;
	if(l==r) return l;
	if(tree[k*2]>=p) update(l,m,k*2,p);
	else
	{
		p-=tree[k*2];
		update(m+1,r,k*2+1,p);
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&pos[i],&w[i]);
		}
		build(1,n,1);
		for(int i=n;i>=1;i--)
		{
			int tmp=update(1,n,1,pos[i]+1);
			res[tmp]=w[i];
		}
		cout<<res[1];
		for(int i=2;i<=n;i++) cout<<" "<<res[i];
		cout<<endl;
	}
	return 0;
}
