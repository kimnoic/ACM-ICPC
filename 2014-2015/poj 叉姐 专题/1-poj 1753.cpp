#include <iostream>
using namespace std;
int cs[16] = {0x13,0x27,78,140,305,626,1252,2248,4880,8992,20032,35968,12544,29184,58368,51200};
int po[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main()
{
	int t=0;
	char tm;
	for(int i=0;i<16;i++)
	{
		cin>>tm;
		if(tm=='b') t+=po[i];
	}
	int res=17;
	for(int i=0;i<65536;i++)
	{
		int v=t;
		int cnt=0;
		for(int j=0;j<16;j++)
		{
			if(i&(int)po[j])
			{
				cnt++;
				v^=cs[j];
			}
		}
		if(v==0||v==65535)
		{
			if(res>cnt) res=cnt;
		}
	}
	if(res==17)
	{
		cout<<"Impossible";
	}
	else cout<<res;
	return 0;
}
