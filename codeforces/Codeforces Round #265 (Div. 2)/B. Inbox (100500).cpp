#include <iostream>
using namespace std;
int a[1010]={};
int b[1010];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
			{
				ans++;
				b[ans]=i;
			}
		}
	int t=ans;
	for(int i=1;i<ans;i++)
	{
		if(b[i+1]-b[i]>=2) t++;
	}
	cout<<t;
	return 0;
}
