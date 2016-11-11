#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define Max 1010
#define Maxn 20010
#define MOD 20007
int xn[Maxn],ynn[Maxn];
struct pt
{
	int x,y;
	int next;
}p[Max];
int hashtable[Maxn];
int n;
int stx,sty;
int gethash(int a,int b)
{
	int temp=a*a+b*b;
	return temp%MOD;
}
void inserthash(int a,int b,int cnt)
{
	int h=gethash(a,b);
	p[cnt].next=hashtable[h];
	hashtable[h]=cnt;
}
bool searchhash()
{
	int h=gethash(stx,sty);
	int next=hashtable[h];
	while(next!=-1)
	{
		if(p[next].x==stx&&p[next].y==sty) return true;
		next=p[next].next;
	}
	return false;
}
int main()
{
	while(cin>>n)
	{
		memset(hashtable,-1,sizeof(hashtable));
		if(n==0) break;
		int tx,ty;
		for(int i=1;i<=n;i++)
		{
			cin>>tx>>ty;
			inserthash(tx,ty,i);
			p[i].x=tx;
			p[i].y=ty;
		}
		int res=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int flag=0;
				if(p[i].x==p[j].x&&p[i].y==p[j].y) continue;
				int xx=p[i].x-p[j].x;
				int yy=p[i].y-p[j].y;
				stx=p[i].x+yy;
				sty=p[i].y-xx;
				if(searchhash()) flag=1;
				if(flag)
				{
					stx=p[j].x+yy;
					sty=p[j].y-xx;
					if(searchhash()) {res++;}
				}
				flag=0;
				stx=p[i].x-yy;
				sty=p[i].y+xx;
				if(searchhash()) flag=1;
				if(flag)
				{
					stx=p[j].x-yy;
					sty=p[j].y+xx;
					if(searchhash()) {res++;}
				}
			}
		}
		cout<<res/8<<endl;
	}
	return 0;
}

