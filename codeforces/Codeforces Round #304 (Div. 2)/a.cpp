#include <bits/stdc++.h>
using namespace std;
long long n,k,w;

int main()
{
	cin>>k>>w>>n;
	long long y=k*(n+1)*n/2;
	if(y-w>0)
	cout<<y-w;
	else cout<<"0";
	return 0;
}
