#include <iostream>
using namespace std;
int po[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int a[4][4]={};
int main()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=4*i;k<4*i+4;k++) a[i][j]+=po[k];
			for(int k=j;k<16;k+=4) a[i][j]+=po[k];
			a[i][j]-=po[4*i+j];
		}
	}
	char tmp;
	int t=0;
	for(int i=0;i<16;i++)
	{
		cin>>tmp;
		if(tmp=='+') t+=po[i];
	}
	int res=17;
	int e;
	for(int k=0;k<65536;k++)
	{
		int v=t;
		int cnt=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(k&po[4*i+j])
				{
					cnt++;
					v^=a[i][j];
				}
			}
		}
		//cout<<cnt<<endl;
		if(v==0)
		{
			if(res>cnt)
			{
				res=cnt;
				e=k;
			}
		}
	}
	cout<<res<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(e&po[4*i+j])
			{
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
	return 0;
}
