#include <bits/stdc++.h>
using namespace std;
#define Max 200010
int n,w;
int a[Max];
int main()
{
	cin>>n>>w;
	int m1=Max,m2=Max;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+2*n+1);
	double ra=(double) a[1];
	double rb=(double) a[n+1];
	if(ra>rb/2) ra=rb/2.0;
	double sum=3*n*ra;
	if(sum>w) sum=w;
	printf("%lf",sum);
	return 0;
}
