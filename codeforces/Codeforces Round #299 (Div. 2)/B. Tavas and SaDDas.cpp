#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
long long a=0,n;
int main()
{
	cin>>n;
	for(int i=1;n>0;n/=10,i++)
	{
		if(n%10==4)
		{
			a+=pow(2,i-1);
		}
		else
		{
			a+=pow(2,i);
		}
	}
	cout<<a;
	return 0;
}
