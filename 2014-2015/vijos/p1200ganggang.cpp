//¸ß½ø¶È½×³Ë
#include <iostream>
#include <math.h>
using namespace std;
int a[3000]={};
int main()
{
	int n;
	cin>>n;
	int t=n;
	a[1]=1;
	int length=1;
	while(1)
	{
		for(int i=1;i<=length;i++)
		{
			a[i]*=n;
		}
		for(int i=1;i<=length;i++)
		{
			if(a[i]>=10)
			{
				a[i+1]+=a[i]/10;
				a[i]%=10;
			}
		}
		for(int i=length+1;;i++)
		{
			//cout<<a[i]<<endl;
			length++;
			if(a[i]<10) break;
			else
			{
				a[i+1]+=a[i]/10;
				a[i]%=10;
			}
		}
		n--;
		if(n==0) break;
	}
	long long sum=0;
	for(int i=1;i<=length;i++) sum+=a[i];
	cout<<sum;
	int flag=1;
    for(int i=2;i<=sqrt(sum);i++)
	{
		if(sum%i==0)
		{
			flag=0;
			break;
		}
	}
	if(t==1) flag=0;
	if(flag==0) cout<<'F';
	else cout<<'T';
	return 0;
}
