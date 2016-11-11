#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
int _case;
int n, A, K, a, b, m, P;
int f[1000010],fl[1000010];
void init()
{
	f[1]=K;
	for(int i=2;i<=n;i++) f[i]=(a*f[i-1]+b)%m;
}
long long c(long long k)
{
	if(k==0) return fl[k]=1;
	if(k==1) return fl[k]=A%P;
	else if(f[k]!=0) return fl[k];
	else if(k%2==0) {return c(k/2)*c(k/2)%P;fl[k]=c(k/2)*c(k/2)%P;}
	else {return c(k/2)*c(k/2)*A%P;fl[k]=c(k/2)*c(k/2)*A%P;}
}
long long res;
int main()
{
	cin>>_case;
	int t=0;
	while(_case--)
	{
		cin>>n>>A>>K>>a>>b>>m>>P;
		memset(fl,0,sizeof(fl));
		init();
		res=0;
		for(int i=1;i<=n;i++)
		{
			res+=c(f[i])%P;
			res%=P;
		}
		cout<<"Case #"<<++t<<": "<<res<<endl;
	}
	return 0;
}
