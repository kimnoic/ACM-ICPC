#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin>>n;
	long long a=9,b=0;
	long long sum=0;
	int k=1;
	while(n>=a)
	{
		sum+=(a-b)*k;
		a*=10;a+=9;
		b*=10;b+=9;
		k++;
	}
	sum+=(n-b)*k;
	cout<<sum;
	return 0;
}
