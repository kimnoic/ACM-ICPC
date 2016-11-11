#include <bits/stdc++.h>
using namespace std;
long long m,h1,h2,a1,a2,x1,x2,y_1,y2;
long long h,num_1,num_2,rep_1,rep_2;
int main()
{
	cin>>m>>h1>>a1>>x1>>y_1>>h2>>a2>>x2>>y2;
    h=h1;
    num_1=0;num_2=0;rep_1=0;rep_2=0;
    for(long long i=1;i<=2*m;i++)
	{
		h=(x1*h+y_1)%m;
		if(h==a1)
		{
			if(num_1==0)
			{
				num_1=i;
			}
			else if(rep_1==0)
			{
				rep_1=i-num_1;
				break;
			}
		}
	}
	h=h2;
	for(long long i=1;i<=2*m;i++)
	{
		h=(x2*h+y2)%m;
		if(h==a2)
		{
			if(num_2==0)
			{
				num_2=i;
			}
			else
			{
				rep_2=i-num_2;
				break;
			}
		}
	}
	if(num_1==0||num_2==0)
	{
		//cout<<"asdf";
		cout<<"-1";
		return 0;
	}
	int flag=1;
	for(long long i=0;i<=m;i++)
	{
		if(rep_2==0)
		{
			if(i*rep_1+num_1==num_2)
			{
				cout<<i*rep_1+num_1;
				return 0;
			}
		}
		else
		{
			if(i*rep_1+num_1>=num_2&&(i*rep_1+num_1-num_2)%rep_2==0)
			{
				cout<<i*rep_1+num_1;
				return 0;
			}
		}
	}
	//cout<<"asdf";
	cout<<"-1";
	return 0;
}
/*
91
9 64
75 32
60 81
35 46

*/
