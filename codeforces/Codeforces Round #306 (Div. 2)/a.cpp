#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.size();
	int a=0,b=0;
	for(int i=0;i<len-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='B')
		{
			a++;i+=1;
		}
		else if(s[i]=='B'&&s[i+1]=='B')
		{
			b++;i+=1;
		}
	}
	if(a>0&&b>0) {cout<<"YES";return 0;}
	a=0;b=0;
	for(int i=len-1;i>0;i--)
	{
		if(s[i]=='A'&&s[i-1]=='B')
		{
			a++;i--;
		}
		else if(s[i]=='B'&&s[i-1]=='A')
		{
			b++;i--;
		}
	}

	if(a>0&&b>0) {cout<<"YES";return 0;}
	cout<<"NO";
	return 0;
}
