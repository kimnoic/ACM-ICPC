#include <bits/stdc++.h>
using namespace std;
int s[5000010];
int d[5000010];
void init()
{
	memset(d,0,sizeof(d));
	for(int i=2;i<=5000000;i++)
	{
		if(d[i]==0)
		{
			for(int j=i;j<=5000000;j+=i)
			{
				int c=j;
				while(c%i==0)
				{
					d[j]++;
					c/=i;
				}
			}
		}
		s[i]=s[i-1]+d[i];
	}
}
int main()
{
	init();
	int T;
	cin>>T;
	int a,b;

	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",s[a]-s[b]);
	}
	return 0;
}
