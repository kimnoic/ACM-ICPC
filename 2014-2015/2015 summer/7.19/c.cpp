#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 1e-10
double fabs(double a)
{
	if(a<0) return -a;
	return a;
}
double cal(double a)
{
	return 8*a*a*a*a+7*a*a*a+2*a*a+3*a+6;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		double n;
		cin>>n;
		double l=0;
		double r=100;
		double mid=(l+r)/2;
		if(cal(l)>n||cal(r)<n)
		{
			cout<<"No solution!"<<endl;
			continue ;
		}

		while(fabs(cal(mid)-n)>(1e-5))
		{
			if(cal(mid)<n)
			{
				l=mid;
				mid=(l+r)/2;
			}
			else
			{
				r=mid;
				mid=(l+r)/2;
			}
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}

