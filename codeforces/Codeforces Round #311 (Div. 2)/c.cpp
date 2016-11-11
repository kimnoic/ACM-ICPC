#include <bits/stdc++.h>
using namespace std;
#define Max 100010
struct pt
{
	int l,d;
}p[Max];
int n;
bool cmp(pt a, pt b)
{
	return a.d<b.d;
}
int hash[Max],mp[233];
int main()
{
	memset(hash,0,sizeof(hash));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].l;
		hash[p[i].l]++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].d;
		mp[p[i].d]++;
	}
	sort(p+1,p+n+1,cmp);
	int temp;
	int cur=n;
	int sum=0;
	int res=233*Max;
	int mus=0;
	int mpp[233];
	for(int i=1;i<=200;i++) mpp[i]=mp[i];
    for(int i=n;i>0;)
	{
		for(int i=1;i<=200;i++) mpp[i]=mp[i];
		sum=0;
		cur=i;
		int pos=i;
		temp=p[i].l;
		while(p[pos].l==temp)
		{
			mpp[p[pos].d]--;
			pos--;
		}
		pos=1;
        cur-=hash[temp]+hash[temp]-1;
        if(cur<=0)
		{
			sum=mus;
		}
		else
		{
			sum+=mus;
			pos=1;
			while(cur)
			{
				while(!mpp[pos]) pos++;
				sum+=pos;
				mpp[pos]--;
				cur--;
			}
		}
		if(res>sum) res=sum;
		pos=i;
		while(p[pos].l==temp)
		{
			mpp[p[pos].d]--;
			mus+=p[pos].d;
			pos--;
		}
	}
	return 0;
}
