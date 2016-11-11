#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int x1_,x2_,y1_,y2_;
	cin>>x1_>>y1_>>x2_>>y2_;
	if (x1_==x2_)
	{
		int d=abs(y1_-y2_);
		printf("%d %d %d %d\n",x1_+d,y1_,x2_+d,y2_);
	}
	else
	if (y1_==y2_)
	{
		int d=abs(x1_-x2_);
		printf("%d %d %d %d\n",x1_,y1_+d,x2_,y2_+d);
	}
	else
	{
		if (abs(x1_-x2_)==abs(y1_-y2_))
		{
			printf("%d %d %d %d\n",x2_,y1_,x1_,y2_);
		}
		else cout<<"-1\n";
	}
	return 0;
}
