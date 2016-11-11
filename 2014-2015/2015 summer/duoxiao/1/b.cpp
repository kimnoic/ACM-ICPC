#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
int fabs(int a)
{
	if(a<0) return -a;
	else return a;
}
using namespace std;
int n;
int t;
int T;
int main()
{
	cin>>T;
	while(T--)
	{
		int k;
		cin>>n>>k;
		int p;
		int pos=1;
		int sum=1;
		cin>>p;
		for(int i=2;i<=n;i++)
		{
			cin>>t;
			sum++;
			if(fabs(t-p)<k)
			{
				sum+=i-pos;
				p=t;
			}
			else
			{
				p=t;
				pos=i;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
