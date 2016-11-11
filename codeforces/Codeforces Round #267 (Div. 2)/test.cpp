#include <iostream>
using namespace std;
#include <string.h>
#include <map>
int main()
{
	map<string ,string> a;
	string s1,s2;
	cin>>s1>>s2;
	a[s1]=s2;
	int l=a[s1].size();
	cout<<l;
	return 0;
}
