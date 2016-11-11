#include <iostream>
#include <stdio.h>
using namespace std;
double d[50][10050];
int main()
{
	int t;
	cin>>t;
	int a,b;
	int c=1;
	while(t--)
	{
		double sum=0;
		cin>>a>>b;
			for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
				cin>>d[i][j];
		}
		for(int i=1;i<=b;i++)
		{
			double t=d[1][i];
			int k=1;
			for(int j=2;j<=a;j++)
			{
				if(d[j][i]>t)
				{
					k=j;
					t=d[j][i];
				}
			}
			sum+=t;
			for(int r=i+1;r<=i+a-1;r++) d[r][k]=-1;
		}
		printf("Case #%d: %.5lf",c,sum);c++;
	}
	return 0;
}
