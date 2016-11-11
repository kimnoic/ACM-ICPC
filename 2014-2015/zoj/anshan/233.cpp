#include <iostream>
#define MOD 10000007
using namespace std;
#define N 20
long long j233(int a)
{
	long long s;
	for(int i=1;i<=a+2;i++)
	{
		if(i==1)
		{
			s=2;
		}
		else s=s*10+3;
	}
	return s%MOD;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cout<<j233(i)<<endl;
	return 0;
}
