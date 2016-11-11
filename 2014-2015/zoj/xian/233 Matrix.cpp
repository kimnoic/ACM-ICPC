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
long long a[N];
int n,m;
long long cal(int a2,long long b)
{
	if(a2==0) return j233(b);
	else if(b==0) return a[a2];
	else if(a2!=0&&b!=0) return (cal(a2-1,b)+cal(a2,b-1))%MOD;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<cal(n,m)<<endl;
	}
	return 0;
}
