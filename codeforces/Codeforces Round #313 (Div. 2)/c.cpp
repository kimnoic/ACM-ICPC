#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int l=a+b+c;
	int sum=l*l;
	sum-=a*a;
	sum-=c*c;
	sum-=e*e;
	cout<<sum;
	return 0;
}
