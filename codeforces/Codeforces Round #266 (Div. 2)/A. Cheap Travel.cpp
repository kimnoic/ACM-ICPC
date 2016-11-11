#include <iostream>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int sum=0;
	if(m*a>b&&(n-m*(n/m))*a<=b)
	{
		int t1=n/m;
		sum+=t1*b;
		int t2=n-t1*m;
		sum+=t2*a;
		cout<<sum;
	}
	else if((n-m*(n/m))*a>b)
	{
		cout<<(n/m+1)*b;
	}
	else
	{
		cout<<a*n;
	}
	return 0;
}
