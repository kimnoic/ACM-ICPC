#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <vector>
using namespace std;
int n;
string s1,s2;
int res=0;
int main()
{
	cin>>n;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		int a=(int)s1[i]-(int)s2[i];
		if(a<0) a=-a;
		a=min(a,10-a);
		res+=a;
	}
	cout<<res;
	return 0;
}
