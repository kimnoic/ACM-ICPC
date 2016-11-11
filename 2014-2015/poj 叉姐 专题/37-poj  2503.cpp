#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define Max 100010
#define MOD 100007
int hashtable[Max];
struct Node
{
	char from[23],to[23];
	int next;
};
Node p[Max];
char k;
int gethash(char a[])
{
	int len=strlen(a);
	int hash=5381;
	for(int i=0;i<len;i++)
	{
		hash=(hash<<5+hash)+a[i];
		hash%=MOD;
	}
	if(hash<0) hash+=MOD;
	return hash%MOD;
}
void inserthash(char a[],int cnt)
{
	int h=gethash(a);
	p[cnt].next=hashtable[h];
	hashtable[h]=cnt;
}
void searchhash(char *a)
{
	int h=gethash(a);
	int next=hashtable[h];
	while(next!=-1)
	{
		if(strcmp(p[next].to,a)==0)
		{
			printf("%s\n",p[next].from);
			//cout<<p[next].from<<endl;
			return ;
		}
		next=p[next].next;
	}
	printf("eh\n");
	//cout<<"eh"<<endl;
	return ;
}

int main()
{
	char tmp[23];
	memset(hashtable,-1,sizeof(hashtable));
	for(int i=1;;i++)
	{
		gets(tmp);
		if(!strlen(tmp)) break;
		sscanf(tmp,"%s %s",p[i].from,p[i].to);
		inserthash(p[i].to,i);
	}
	char t[23];
	while(~scanf("%s",t))
	{
		searchhash(t);
	}
	return 0;
}

