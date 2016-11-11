#include <iostream>
#include <string.h>
using namespace std;
int n;
int k[5][20];
int main()
{
	cin>>n;
	while(n--)
	{
		memset(k,0,sizeof(k));
		char tmp;
		int b;
		for(int i=1;i<=5;i++){
		cin>>tmp>>b;
		int a=tmp-'A'+1;
		if(b==1) k[a][b+13]=1;
		k[a][b]=1;}
		int sum=0;
		int cnt;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j+4<=14;j++)
			{
				cnt=0;
				for(int kk=0;kk<5&&j+kk<=14;kk++)
				{
					cnt+=k[i][j+kk];
				}
				sum=max(sum,cnt);
			}
		}
		cout<<5-sum;
		if(n!=0) cout<<endl;
	}
	return 0;
}
