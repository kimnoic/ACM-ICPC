#include <iostream>
#define N 20010
using namespace std;
int a[N]={};
int b[31];
int n;
int num;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	cin>>n>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=num;i++)
	{
		for(int j=n;j>=b[i];j--)
		{
			a[j]=max(a[j],a[j-b[i]]+b[i]);
		}
	}
	cout<<n-a[n];
	return 0;
}
