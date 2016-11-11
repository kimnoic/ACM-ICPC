#include <iostream>
#include <string.h>
#include <map>
using namespace std;
string s1,s2,s3;
char b[10010][100];
int c[10010]={};
map<string ,string >a;
int n,m;
int main()
{
	long long num1=0,num2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s1>>s2;
		s3=a[s1];
		if(s3.size()!=0)
		{if(s2.size()<s3.size()) a[s1]=s2;}
		else a[s1]=s2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[b[i]].size()!=0)
		{
			cout<<i<<endl;
			num1++;
			num2+=a[b[i]].size();
		}
		else
		{
			string s4=b[i];
			num2+=s4.size();
		}
	}
	cout<<num1<<" "<<num2;
	return 0;
}
