#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
int T;
long long n;
long long res;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		res=0;
		int flag=0;
		while(n>0)
		{
			if(!flag&&n%2==1)
			{
				flag=1;
				n/=2;
				res++;
			}
			else if(n%2==0)
			{
				flag=0;
				n/=2;
			}
			else n/=2;
		}
		cout<<res<<endl;
	}
	return 0;
}
