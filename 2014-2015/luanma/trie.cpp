#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define Max 500010
struct node
{
	int x;
	node *next[26];
};
int degree[Max],fa[Max],cnt,ant;
node *root , mem[Max*10];
node * create()
{
	node * p =&mem[ant++];
	for(int i=0;i<26;i++)
	{
		p->next[i]=NULL;
	}
	return p;
}
void insert(char *s,int x)
{
	node * p =root;
	int k;
	for(int i=0;i<strlen(s);i++)
	{
		k=s[i]-'a';
		if(p->next[k]==NULL)
		{
			p->next[k]=create();
		}
		p=p->next[k];
	}
	p->x=x;
}
int search(char *s)
{
	node *p = root;
	int k;
	for(int i=0;i<strlen(s);i++)
	{
		k=s[i]-'a';
		if(p->next[k]==NULL) {return 0;}
		p=p->next[k];
	}
	return p->x;
}
void init()
{
	for(int i=1;i<=Max;i++)
	{
		fa[i]=i;
	}
	memset(degree,0,sizeof(degree));
}
int find(int x)
{
	if(x!=fa[x])
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void Union(int a,int b)
{
	fa[a]=b;
}
bool judge()
{
	int u=0;
	for(int i=1;i<=cnt;i++)
	{
		u+=degree[i]%2;
	}
	if(u>2||u==1) return false;
	u=find(1);
	for(int i=2;i<=cnt;i++)
	{
		if(find(i)!=u) {cout<<i;return false;}
	}
	return true;
}
int main()
{
	int x,y;
	int xx,yy;
	char s1[15],s2[15];
	init();
	root = create();
	cnt =0 ;
	while(~scanf("%s %s",s1,s2))
	{
		x=search(s1);
		y=search(s2);
		if(x==0) insert(s1,x = ++cnt);
		if(y==0) insert(s2,y = ++cnt);
		degree[x]++;
		degree[y]++;
		xx=find(x);
		yy=find(y);
		if(xx!=yy)
		{
			Union(xx,yy);
		}
	}
	if(judge()) cout<<"Possible";
	else cout<<"Impossible";
	return 0;
}
