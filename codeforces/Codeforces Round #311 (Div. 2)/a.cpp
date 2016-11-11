#include <bits/stdc++.h>
using namespace std;
int n;
int min1,min2,min3,max1,max2,max3;
int main()
{
	cin>>n;
	cin>>min1>>max1;
	cin>>min2>>max2;
	cin>>min3>>max3;
	int a=min1,b=min2,c=min3;
	n-=min1;
	n-=min2;
	n-=min3;
	int t;
	t=max1-min1;
	if(t>=n)
	{
		a+=n;
		cout<<a<<" "<<b<<" "<<c;
		return 0;
	}
	a+=t;
	n-=t;
	t=max2-min2;
	if(t>=n)
	{
		b+=n;
		cout<<a<<" "<<b<<" "<<c;
		return 0;
	}
	b+=t;
	n-=t;
	c+=n;
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
