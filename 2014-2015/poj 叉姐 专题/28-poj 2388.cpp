#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <stack>
#include <string.h>
#include <map>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[23333];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[n/2];
	return 0;
}
