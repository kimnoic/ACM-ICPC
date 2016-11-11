#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	char t[2333];
	int b[2333],c[2333],n;
	while(cin>>t>>n)
	{
		int len=strlen(t);
		int top=0;
		for(int i=0;i<len;i++)
		{
			b[i]=t[i]-'0';
		}
		int pos;
		for(int i=0;i<len-1&&n>0;i++)
		{
			if(b[i]<=b[i+1])
			{
				c[top++]=b[i];
			}
			else
			{
				n--;
				while(n>0&&c[top-1]>b[i+1])
				{
					top--;
					n--;
				}
			}
			pos=i;
		}
		for(int i=pos+1;i<len;i++)
		{
			c[top++]=b[i];
		}
		pos=0;
		for(int i=0;i<top-n;pos=++i)
		{
			if(c[i]!=0) break;
		}
		if(pos==top-n) cout<<0<<endl;
		else
			{
				for(int i=pos;i<top-n;i++)
				{
					cout<<c[i];
				}
				cout<<endl;
			}
	}
	return 0;
}
