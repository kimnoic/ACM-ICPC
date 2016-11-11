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
#define INF 0x3ffffffff
int n;int b[5010]={};
int fab(int a,int b)
{
	if(a>b) return a-b;
	else return b-a;
}
int main()
{
	while(cin>>n)
	{
		if(n<=4)
		{
			if(n==1||n==2) cout<<"1"<<endl<<"1";
		else if(n==3) cout<<2<<endl<<"1 3";
		else cout<<4<<endl<<"2 4 1 3";
		}
	else
	{int top=1;
	for(int i=1;i<=n;i+=2)
	{
		b[top]=i;
		top+=1;
	}
	for(int i=2;i<=n;i+=2)
	{
		if(i==2&&fab(i,b[top-1])==1) break;
		else
		{
			b[top]=i;
			top++;
		}
	}
	top--;
	cout<<top<<endl;
	for(int i=1;i<=top;i++) cout<<b[i]<<" ";
	cout<<endl;}}
	return 0;
}
