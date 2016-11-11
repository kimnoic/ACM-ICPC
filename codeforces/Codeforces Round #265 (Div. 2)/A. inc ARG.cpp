#include <iostream>
#include <string.h>

int n;
using namespace std;
int main()
{
	string s;
	cin>>n;
	cin>>s;
	int length=s.size();
	int ans=0;
	for(int i=0;i<length;i++)
	{
		if(s[i]=='1') ans++;
		if(s[i]=='0')
		{
			ans++;
			break;
		}
	}
	cout<<ans;
	return 0;
}
