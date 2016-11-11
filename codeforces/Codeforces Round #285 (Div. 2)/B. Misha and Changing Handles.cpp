#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
#define Max 1010
map<string,string>mapp;
string a,b;
int main()
{
	int n;
	cin>>n;
	int cnt=n;
	while(n--)
	{
		cin>>a>>b;
		if(mapp.find(a)==mapp.end())
		mapp[b]=a;
		else
		{
			string t=mapp[a];
			mapp.erase(a);
			mapp[b]=t;
			cnt--;
		}
	}
	cout<<cnt<<endl;
	map<string,string>::iterator i;
	for(i=mapp.begin();i!=mapp.end();++i)
		cout<<i->second<<" "<<i->first<<endl;
	return 0;
}
