#include <iostream>
using namespace std;
int p[111],q[111];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>q[i];
		if(q[i]-p[i]>=2)ans++;
	}
	cout<<ans;
	return 0;
}
