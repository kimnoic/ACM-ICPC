#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int c[2333];
int cal(int a,int b)
{
	int ans=0;
	for(int i=a;i<=b;i++)
	{
		int flag=0;
		for(int j=a;j<=b;j++)
		{
			if(i==j) continue;
			if(c[i]%c[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag) {ans++;cout<<a<<" "<<b<<endl;}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum+=cal(i,j);
		}
	}
	cout<<sum<<endl;
	return 0;
}
