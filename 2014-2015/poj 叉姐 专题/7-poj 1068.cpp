#include <iostream>
using namespace std;
int p[233];
int l[233];
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			l[i]=p[i]-p[i-1];
			int k=i;
			while(l[k]==0) k--;
			l[k]--;
			cout<<i-k+1;
			if(i!=n) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
