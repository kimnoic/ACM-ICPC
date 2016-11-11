#include <iostream>
#include <string.h>
using namespace std;
int T;
string s;
int n;
int len;
int a,b;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		a=0;
		b=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			len=s.size();
			if(len%2) a++;
			else b++;
		}
		if(a==0) cout<<"0/1"<<endl;
		else if(b==0) cout<<"1/1"<<endl;
		else
		{
			long long aa=2*a*b;
			long long bb=(a+b)*(a+b-1);
			cout<<aa/gcd(aa,bb)<<"/"<<bb/gcd(aa,bb)<<endl;
		}
	}
	return 0;
}
