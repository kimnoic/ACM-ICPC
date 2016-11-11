#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
char a[110],b[110];
int main()
{
	cin>>a>>b;
	int len=strlen(a);
	a[len-1]++;
	for(int i=len-1;i>=0;i--)
		if(a[i]>'z')
	{
		a[i-1]++;
		a[i]='a';
	}
	if(strcmp(a,b)==0)
		cout<<"No such string";
	else
		cout<<a;
	return 0;
}
