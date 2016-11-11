#include <iostream>
using namespace std;
int top=0;
bool prime(int a)
{
	for(int i=2;i*i<=a;i++)
		if(a%i==0) return false;
	return true;
}
int m[3600];
int main()
{
	int t;
	for(int i=2;top<=3505;i++)
		if(prime(i))
	{
		m[top]=i;
		top++;
	}
	while(cin>>t)
	{
		if(t==0) break;
		int result=0;
		for(int i=t-2;i>=0;i--)
			result=(result+m[i])%(t-i);
		cout<<result+1<<endl;
	}
	return 0;
}
