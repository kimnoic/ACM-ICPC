#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	int a1,b1,a2,b2;
	cin>>x>>y;
	cin>>a1>>b1>>a2>>b2;
	int temp;
	if(x<y)
	{
		temp=y;
		y=x;
		x=temp;
	}
	if(a1<b1)
	{
		temp=a1;
		a1=b1;
		b1=temp;
	}
	if(a2<b2)
	{
		temp=a2;
		a2=b2;
		b2=temp;
	}
    int xx=max(a1,a2);
    int yy=b1+b2;
    if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	xx=a1+a2;
	yy=max(b1,b2);
	if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
    xx=a1+b2;
    yy=max(a2,b1);
    if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	xx=a2+b1;
	yy=max(a1,b2);
	if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	temp=y;
    y=x;
    x=temp;xx=max(a1,a2);yy=b1+b2;if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	xx=a1+a2;
	yy=max(b1,b2);
	if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
    xx=a1+b2;
    yy=max(a2,b1);
    if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	xx=a2+b1;
	yy=max(a1,b2);
	if(xx<=x&&yy<=y)
	{
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
	return 0;
}
