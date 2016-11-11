#include<bits/stdc++.h>
using namespace std;
int m,n,kk,k;
double l,v1,v2,x,ans;
int main(){
	cin>>n>>l>>v1>>v2>>k;
	int q=1;
	kk=n/k+((n%k!=0)?0:-1);
	double y=((v1+v2)*(kk+1)-(v2-v1)*kk);
	x=1.0*(v1+v2)*l/y;
	q++;
	ans=x/v2+(l-x)/v1;
	if(q)printf("%.10f",ans);
	return 0;
}
