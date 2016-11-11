#include <bits/stdc++.h>
using namespace std;
queue <int > s1;
queue <int > s2;
int main()
{
	int n;
	cin>>n;
	int k1,k2;
	cin>>k1;
	int t;
	for(int i=1;i<=k1;i++)
	{
		cin>>t;
		s1.push(t);
	}
	cin>>k2;
	for(int i=1;i<=k2;i++)
	{
		cin>>t;
		s2.push(t);
	}
	int cnt=0;
	int flag=0;
	while(!s1.empty()&&!s2.empty())
	{
		int t1=s1.front();
		int t2=s2.front();
		s2.pop();
		s1.pop();
		if(t1>t2)
		{
			s1.push(t2);
			s1.push(t1);
			cnt++;
		}
		else
		{
			s2.push(t1);
			s2.push(t2);
			cnt++;
		}
		if(cnt>10000000)
		{
			flag=1;
			break;
		}
	}
	if(flag) cout<<"-1";
	else if(s1.empty()) cout<<cnt<<" 2";
	else cout<<cnt<<" 1";
	return 0;
}
