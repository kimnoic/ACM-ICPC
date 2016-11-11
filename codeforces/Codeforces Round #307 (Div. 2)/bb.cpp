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
    int y=max(minb,minc);
    for(int i=0;i<=minb;i++)
	{
		int u=Max;
		for(int j=1;j<=26;j++)
		{
			if(cl[j]!=0)
			{
				u=min(u,(al[j]-bl[j]*i)/cl[j]);
			}
		}
		if(u!=Max)
		{
			if(u+i>sum)
			{
				sum=u+i;
				bb=i;
				cc=u;
			}
		}
	}
	for(int i=1;i<=26;i++)
	{
		al[i]-=(bl[i]*bb+cl[i]*cc);
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
	return 0;
}
