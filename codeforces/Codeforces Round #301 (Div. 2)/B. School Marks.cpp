#include <iostream>
#include <algorithm>
using namespace std;
int n,k,p,x,y;
int sc[1100];
int res=0;
int cnt=0;
int sum=0;
int main()
{
	cin>>n>>k>>p>>x>>y;
	for(int i=0;i<k;i++)
	{
		cin>>sc[i];
		if(sc[i]>=y)
		{
			res+=sc[i];
			cnt++;
		}
		sum+=sc[i];
	}
	if(cnt>=(n+1)/2)
	{
		sum+=n-k;
		if(sum>x) cout<<"-1";
		else
		{
			sort(sc,sc+n);
			for(int i=1;i<=n-k;i++) cout<<"1"<<" ";
		}
	}
	else
	{
		for(int i=k;i<k+(n+1)/2-cnt;i++) {sc[i]=y;sum+=y;}
		for(int i=k+(n+1)/2-cnt;i<n;i++) {sc[i]=1;sum++;}
		sort(sc,sc+n);
		if(sum<=x)
		{
			for(int i=k;i<k+(n+1)/2-cnt;i++) {cout<<y<<" ";}
			for(int i=k+(n+1)/2-cnt;i<n;i++) {cout<<1<<" ";}

		}
		else cout<<"-1";
	}
	return 0;
}
