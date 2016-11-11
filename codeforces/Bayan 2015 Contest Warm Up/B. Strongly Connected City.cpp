#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m;
char s1[30],s2[30];
int v[30][30]={};
int c[30][30]={};

void dfs(int a,int b)
{
	if(a<1||a>n||b<1||b>m||v[a][b]==1) return ;
	//cout<<a<<" "<<b<<endl;
		c[a][b]++;
		v[a][b]=1;
		if(s1[a]=='<') dfs(a,b-1);
		else dfs(a,b+1);
		if(s2[b]=='^') dfs(a-1,b);
		else dfs(a+1,b);
}
int main(void)
{
	cin>>n>>m;
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
	{
		memset(v,0,sizeof(v));
		dfs(i,j);
	}
	int sum=n*m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
	{
		//cout<<c[i][j];
		if(sum!=c[i][j])
		{
			cout<<"NO";return 0;
		}
		//cout<<endl;
	}
	cout<<"YES";
	return 0;
}

