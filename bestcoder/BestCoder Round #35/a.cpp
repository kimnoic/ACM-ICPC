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
#define INF 0x3fffffffff
using namespace std;
int n,m;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
long long sum_1,sum_2;
int main()
{
	while(cin>>n>>m)
	{
		int t=gcd(m*n,m+n);
		cout<<m*n/t<<"/"<<(m+n)/t<<endl;
	}
	return 0;
}
