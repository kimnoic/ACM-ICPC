#include <bits/stdc++.h>
using namespace std;
#define Max 100010
string a,b,c;
int al[30],bl[30],cl[30];
int bb,cc;
int main()
{
	cin>>a;
	cin>>b;
	cin>>c;
	int la=a.size();
	int lb=b.size();
	int lc=c.size();
	for(int i=0;i<la;i++)
	{
		al[a[i]-'a'+1]++;
	}
	for(int i=0;i<lb;i++)
	{
		bl[b[i]-'a'+1]++;
	}
	for(int i=0;i<lc;i++)
	{
		cl[c[i]-'a'+1]++;
	}
	int minb=Max,minc=Max;
	for(int i=1;i<=26;i++)
	{
		if(bl[i]!=0)
		{
			minb=min(minb,al[i]/bl[i]);
		}
	}
	for(int i=1;i<=26;i++)
	{
		if(cl[i]!=0)
		{
			minc=min(minc,al[i]/cl[i]);
		}
	}
    int sum=0;
    if(minb>minc)
	{
		bb=minb;
		for(int i=1;i<=26;i++)
		{
			al[i]-=bl[i]*bb;
		}
		cc=Max;
		for(int i=1;i<=26;i++)
		{
			if(cl[i]!=0)
			{
				cc=min(cc,al[i]/cl[i]);
			}
		}
		for(int i=1;i<=26;i++)
		{
			al[i]-=cl[i]*cc;
		}
		for(int i=1;i<=bb;i++) cout<<b;
		for(int i=1;i<=cc;i++) cout<<c;
		for(int i=1;i<=26;i++)
		{
			for(int j=1;j<=al[i];j++)
			{
				cout<<(char)(i+'a'-1);
			}
		}
	}
	else
	{
		cc=minc;
		for(int i=1;i<=26;i++)
		{
			al[i]-=cl[i]*cc;
		}
		bb=Max;
		for(int i=1;i<=26;i++)
		{
			if(bl[i]!=0)
			{
				bb=min(bb,al[i]/bl[i]);
			}
		}
		for(int i=1;i<=26;i++)
		{
			al[i]-=bl[i]*bb;
		}
		for(int i=1;i<=bb;i++) cout<<b;
		for(int i=1;i<=cc;i++) cout<<c;
		for(int i=1;i<=26;i++)
		{
			for(int j=1;j<=al[i];j++)
			{
				cout<<(char)(i+'a'-1);
			}
		}
	}

	return 0;
}
