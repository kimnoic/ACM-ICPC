#include <iostream>
#include <string.h>
using namespace std;
int n,d1,d2,y1,y2;
string s1,s2;
int f1(string s,int d,int y)
{
	int flag=0,res=0;
	if(s[0]!='J'||s[1]!='a')
	{
		if(s[0]!='F')
			flag=1;
	}
	if(y==2000&&flag==0) return res;
	else
	{
		if(!flag) y--;
		y=y-2000;
		int k=y/400;
		res+=k*97;
		k=(y%400)/100;
		res+=k*24;
		k=(y%100)/4;
		res+=k;
		return res;

	}
}
int f2(string s,int d,int y)
{
	int flag=0,res=0;
	if(s[0]!='J'||s[1]!='a')
	{
		if(s[0]!='F')
			flag=1;
		else if(d==29) flag=1;
	}
	if(y==2000&&flag==0) return res;
	else
	{
		if(!flag) y--;
		y=y-2000;
		int k=y/400;
		res+=k*97;
		k=(y%400)/100;
		res+=k*24;
		k=(y%100)/4;
		res+=k;
		return res;

	}
}
int main()
{
	int _case=1;
	cin>>n;
	char t;
	while(n--)
	{
		cin>>s1>>d1>>t>>y1;
		cin>>s2>>d2>>t>>y2;
		int a=f1(s1,d1,y1);
		int b=f2(s2,d2,y2);
		cout<<"Case #"<<_case++<<": "<<b-a<<endl;
	}
	return 0;
}
