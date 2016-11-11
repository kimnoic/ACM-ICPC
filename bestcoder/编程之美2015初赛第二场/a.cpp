#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <math.h>
using namespace std;
int c[20],tt[20];
int judge(char a)
{
	if(a=='A') return 1;
	else if(a=='T') return 10;
	else if(a=='J') return 11;
	else if(a=='Q') return 12;
	else if(a=='K') return 13;
	else return (int)a-48;
}
char t1,t2;
int _case;
int n;
#define M 18446744073709551616
long long res;
long long dp(int a,int b,long long cc)
{
	if(b==n) return c[a]*cc;
	else if(c[a]==0) return 0;
	else
	{
		int tmp=c[a];
		cout<<"t"<<tmp<<endl;
		c[a]--;
		for(int i=1;i<=13;i++)
		{
			if(c[i]!=0&&i!=a)
			{
				cout<<i<<" "<<b<<endl;
				dp(i,b+1,cc*tmp);
			}
			else if(n-b<=c[a]) return 0;
		}
		c[a]++;
	}
}
int main()
{
	cin>>_case;
	int ca=1;
	while(_case--)
	{
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>t1>>t2;
			int y=judge(t1);
			c[y]++;
		}
		for(int i=1;i<=13;i++) {tt[i]=c[i];}
		long long sum=0;
		for(int i=1;i<=13;i++)
		{
			if(c[i]!=0)
			{
				sum+=dp(i,1,1);
				for(int i=1;i<=13;i++) c[i]=tt[i];
			}
		}
		cout<<"Case #"<<ca++<<": ";
		cout<<sum<<endl;
	}
	return 0;
}
//1 1 TT
