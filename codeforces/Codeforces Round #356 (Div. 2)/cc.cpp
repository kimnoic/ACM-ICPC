#include<bits/stdc++.h>
using namespace std;

int f[111];
int cnt;
priority_queue<int,vector<int>,greater<int> >q;

int prime(int u)
{
	for(int i=2;i<=sqrt(u);i++)
		if(u%i==0)
			return 0;
	return 1;
}
int main()
{
	for(int i=2;i<=100;i++)
		if(prime(i))
		{
			f[++cnt]=i;
			q.push(i);
		}
	string str;
	//cout<<q.top()<<endl;
	int tims = 0;
	for(;;)
	{
		int u=q.top();
		cout<<u<<endl;
		q.pop();
		cin>>str;
		if(str=="yes")
		{
			q.push(u*u);
			tims++;
			if(tims==2)
			{
				cout<<"composite"<<endl;
				return 0;
			}
		}
		if(q.top()>50)
		{
			cout<<"prime"<<endl;
			return 0;
		}
	}
	return 0;
}
