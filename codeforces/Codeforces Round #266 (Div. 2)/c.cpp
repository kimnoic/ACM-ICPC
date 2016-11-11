#include <iostream>
using namespace std;
#define N 500010
long long n,a[N],s[N],antis[N],num[N],need,ans;
int main()
{
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	s[n+1]=0;
	for(int i=n;i>=1;i--) antis[i]=antis[i+1]+a[i];
	if(s[n]%3!=0) {cout<<"0";return 0;}
	need=s[n]/3;
	num[n+1]=0;
	for(int i=n;i>=1;i--)
		if(antis[i]==need)
		{
			num[i]=num[i+1]+1;
		}
		else num[i]=num[i+1];
	ans=0;
	for(int i=1;i<=n-2;i++)
	{
		if(s[i]==need)
			ans+=num[i+2];
	}
	cout<<ans;
	return 0;
}
