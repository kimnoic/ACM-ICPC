#include <iostream>
#include <string.h>
using namespace std;
int T;int m,n;
char t;
int a[5][1010],b[5][233],c[5][1010];
int main()
{
	cin>>T;
	int _case=0;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>t>>a[2][i]>>t>>a[3][i]>>t>>a[4][i];
			//cout<<a[1][i]<<" "<<a[2][i]<<" "<<a[3][i]<<" "<<a[4][i]<<endl;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[1][i]>>t>>b[2][i]>>t>>b[3][i]>>t>>b[4][i];
		}
		cout<<"Case #"<<++_case<<":"<<endl;
		for(int i=1;i<=m;i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=4;k++)
				{
					c[k][j]=a[k][j]&b[k][i];
					//cout<<c[k][j]<<" ";
				}
				//cout<<endl;
				int flag=1;
				int f=1;
				for(int r=1;r<j;r++)
				{
					f=1;
					for(int k=1;k<=4;k++)
					{
						if(c[k][j]!=c[k][r])
						{
							f=0;
							break;
						}
					}
					if(f==1)
					{
						flag=0;
						//cout<<r<<endl;
						break;
					}
				}
				if(flag) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
