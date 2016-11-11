#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
set<long long>a,b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a.insert(x);b.insert(y);
		cout<<(n-a.size())*(n-b.size())<<" ";
	}
	return 0;
}
