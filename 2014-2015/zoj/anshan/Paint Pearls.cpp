#include <iostream>
#define N 50010
using namespace std;
long long ta[N];
long long tag[N];
int n;
int ans=0;
int main()
{
	while(cin>>n)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>ta[i];
			if(i>=2&&ta[i]==ta[i-1])
			{
				ans++;
			}
			else if(i>=2)
			{
				tag[i-ans]=ta[i];
			}
			else if(i==1) tag[i]=ta[i];
		}
		for(int i=1;i<=n-ans;i++) cout<<tag[i]<<endl;
	}
	return 0;
}
