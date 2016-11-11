#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define Max 20010
int _case,n,record[Max],mp[Max*2][2],res;

struct node
{
	int l,r,c;
}nodes[Max*4];

struct Line
{
	int point ,num;
}line[Max*2];

int cmp(const Line &a,const Line &b)
{
	return a.point<b.point;
}

void build(int l,int r,int p)
{
	nodes[p].l=l;
	nodes[p].r=r;
	nodes[p].c=0;
	int mid=(l+r)/2;
	if(l==r) return ;
	else
	{
		build(l,mid,p*2);
		build(mid+1,r,p*2+1);
	}
}
void insert(int l,int r,int p,int c)
{
	if(nodes[p].l==l&&nodes[p].r==r)
	{
		nodes[p].c=c;
		return ;
	}
	if(nodes[p].c>0)
	{
		nodes[2*p].c=nodes[p].c;
		nodes[2*p+1].c=nodes[p].c;
		nodes[p].c=0;
	}
	if(l>=nodes[p*2+1].l)
	{
		insert(l,r,2*p+1,c);
	}
	else if(r<=nodes[p*2].r)
	{
		insert(l,r,2*p,c);
	}
	else
	{
		insert(l,nodes[p*2].r,p*2,c);
		insert(nodes[p*2+1].l,r,p*2+1,c);
	}
}


void query(int p)
{
	if(nodes[p].c!=0)
	{
		if(!record[nodes[p].c])
		{
			res++;
			record[nodes[p].c]=1;
		}
		return ;
	}
	query(p*2);
	query(p*2+1);
	return ;
}

int main()
{
	cin>>_case;
	while(_case--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>mp[i][0]>>mp[i][1];
			line[i*2].point=mp[i][0];
			line[i*2+1].point=mp[i][1];
			line[i*2].num=i+1;
			line[i*2+1].num=i+1;
		}
		sort(line,line+2*n,cmp);
		int temp=line[0].point;
		int count=1;
		for(int i=0;i<2*n;i++)
		{
			if(temp!=line[i].point)
			{
				count++;
				temp=line[i].point;
			}
			if(line[i].num < 0)
                mp[-line[i].num - 1][0] = count;
            else
                mp[line[i].num - 1][1] = count;
		}
		build(1,count,1);
		for(int i=0;i<n;i++)
			insert(mp[i][0],mp[i][1],1,i+1);
		memset(record,0,sizeof(record));
		res=0;
		query(1);
		cout<<res<<endl;
	}
	return 0;
}
