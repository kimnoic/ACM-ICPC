#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;
char t1[100010];
int a[100010];
int main()
{
	cin>>t1;
	int len=strlen(t1);
	int flag=0;
	int pos=0;
	int t=0;
	int k=0;
	for(int i=len-2;i>=0;i--)
	{
		if((t1[i]-'0')%2==0)
		{
			a[k]=i;
			k++;
			if(t1[i]<t1[len-1]) {pos=i;flag=1;}
		}
	}
	if(flag==1)
	{
		char tt=t1[pos];
		t1[pos]=t1[len-1];
		t1[len-1]=tt;
		cout<<t1;
	}
	else if(k!=0)
	{
		int y=a[0];
		char tt=t1[y];
		t1[y]=t1[len-1];
		t1[len-1]=tt;
		cout<<t1;
	}
	else
		cout<<"-1";
	return 0;
}
