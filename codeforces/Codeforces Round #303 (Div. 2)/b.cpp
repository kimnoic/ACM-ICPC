#include <bits/stdc++.h>
using namespace std;
char s1[100100],s2[100100];
char t[100100];
int main()
{
	cin>>s1>>s2;
	int len=strlen(s1);
	int y=1;
	for(int i=0;i<len;i++)
	{
		if(s1[i]==s2[i])
		{
			t[i]=s1[i];
		}
		else if(y==1)
		{
			t[i]=s1[i];
			y=0;
		}
		else
		{
			t[i]=s2[i];
			y=1;
		}
	}
	if(y==1) cout<<t;
	else cout<<"impossible";
	return 0;
}
