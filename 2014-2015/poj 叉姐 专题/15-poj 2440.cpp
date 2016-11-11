#include <iostream>
using namespace std;
int f[233];
long long a;
int main()
{
	f[0]=1;
	f[1]=2;
	f[2]=4;
	f[3]=6;
	f[4]=9;
	f[5]=15;
	for(int i=6;i<=200;i++)
	{
		f[i]=(f[i-1]+f[i-3]+f[i-4])%2005;
	}
	while(cin>>a)
	{
        int b=a%200;
        cout<<f[b]<<endl;
	}
	return 0;
}
