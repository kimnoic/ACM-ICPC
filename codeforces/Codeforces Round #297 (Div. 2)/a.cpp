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
#define INF 0x3ffffffff
int n;
char a,b;
int aa[27];
int sum=0;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		aa[a-'a']++;
		if(aa[b-'A']==0) sum++;
		else aa[b-'A']--;
	}
	cout<<sum;
	return 0;
}
