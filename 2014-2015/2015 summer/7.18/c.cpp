#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
char t;
int n;
int main()
{
	cin>>n;
	int a=0;
	int b=0;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t=='0') a++;
		else b++;
	}
	int minn=min(a,b);
	cout<<n-2*minn;
	return 0;
}
