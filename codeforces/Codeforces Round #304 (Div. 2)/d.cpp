#include <bits/stdc++.h>
using namespace std;
int n;
long long a,b;
int shu[2000];
int top=2;
int s[5000010];
int main()
{
	shu[1]=2;
	shu[2]=3;
	for(int i=2;i<=2236;i++)
	{
		int flag=1;
		for(int j=2;j*j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			top++;
			shu[top]=i;
		}
	}
	/*
	cin>>n;
	while(n--)
	{
		cin>>a>>b;

	}
	*/
    for(int i=1;i<=5000000;i++)
	{
		int t=i;
		for(int j=1;j<top;j++)
		{
			if(t%shu[j]==0)
			{
				s[i]++;
				t/=shu[j];
				j--;
			}
		}
	}
	return 0;
}
