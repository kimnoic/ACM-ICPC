#include <iostream>
using namespace std;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	long long n,a,b;
	int f=0;
	cin>>n>>a>>b;
	if(a<b) f=1;
	if(a*b>=6*n) cout<<a*b<<endl<<a<<" "<<b;
	else if(6*n-a*b<=max(a,b))
	{
		if(f==1)
		{
			if(6*n<=a*(b+1)) cout<<a*(b+1)<<endl<<a<<" "<<b+1;
			else cout<<(a+1)*b<<endl<<a+1<<" "<<b;
		}
		else
		{
			if(6*n<=b*(a+1)) cout<<(a+1)*b<<endl<<a+1<<" "<<b;
			else cout<<a*(b+1)<<endl<<a<<" "<<b+1;
		}
	}
	else
	{
	for(;;)
	{
		if(a>b) a++;
		else b++;
		if(a*b>=6*n)
		{
			cout<<a*b<<endl<<a<<" "<<b;
			break;
		}
	}
	}
	return 0;
}
