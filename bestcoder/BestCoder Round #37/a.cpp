#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int n;
string s;
int t=0;
bool flag=false;
int main()
{
	while(cin>>n)
	{
		flag=false;
		cin>>s;
		t=1;
		for(int i=n-1;i>=(n+1)/2;i--)
			if(s[i]=='?')
			{
				t=0;
				break;
			}
		if(t==0)
		{for(int i=0;i<(n+1)/2;i++)
		{
			if(s[i]=='?')
				s[i]='a';
		}
		for(int i=n-1;i>=(n+1)/2;i--)
			if(s[i]!='?')
		{
			if(s[i]!=s[n-1-i])
			{
				flag=true;
				break;
			}
		}
		for(int i=n-1;i>=(n+1)/2;i--)
		{
			if(!flag)
			{
				if(s[i]=='?')
				{
					if(s[n-1-i]=='a')
						s[i]='b';
					else s[i]='a';flag=true;
				}

			}
			else if(s[i]=='?') s[i]='a';
		}
		if(!flag)
			cout<<"QwQ"<<endl;
		else
			cout<<s<<endl;}
		else
		{
			if(n%2==1) s[n/2]='a';
			for(int i=n/2-1;i>=0;i--)
			{
				if(s[i]!='?'&&s[i]!=s[n-1-i])
				{
					flag=true;
					break;
				}
			}
			for(int i=n/2-1;i>=0;i--)
			{
				if(!flag)
				{
					if(s[i]=='?')
					{
						if(s[n-1-i]=='a') s[i]='b';
						else s[i]='a';
						flag=true;
					}
				}
				else if(s[i]=='?') s[i]='a';
			}
			if(!flag)
			cout<<"QwQ"<<endl;
		else
			cout<<s<<endl;}
	}
	return 0;
}
