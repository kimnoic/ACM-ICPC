#include <bits/stdc++.h>
using namespace std;
const int maxn = 233;

int f[maxn];
int n,a,sum;
int main(){
	cin>>n>>a;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sum=f[a];
	int cnt=1;
	for(int i=1;i<=n;i++){
		int l=a-i;
		int r=a+i;
		if(l>=1&&r>n)
            sum+=f[l];
		if(l>=1&&r<=n){
			if(f[l]==1&&f[r]==1)
				sum+=2;
		}
		if(l<1&&r<=n)
			sum+=f[r];
	}
    cout<<sum;
	return 0;
}
