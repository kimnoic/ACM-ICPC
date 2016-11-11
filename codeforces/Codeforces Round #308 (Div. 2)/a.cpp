#include <bits/stdc++.h>
using namespace std;
int n;
int x1,yy1,x2,y2;
int main()
{
	cin>>n;
	int sum=0;
	while(n--)
	{
		cin>>x1>>yy1>>x2>>y2;
		sum+=(x2-x1+1)*(y2-yy1+1);
	}
	cout<<sum;
	return 0;
}
