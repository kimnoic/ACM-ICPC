#include <iostream>
#include <algorithm>
using namespace std;
bool compare (int a,int b)
{
	return a<b;
}
int main()
{
	int a,b,t;
	int st[10000];
	while(cin>>a>>b)
	{
		for(int i=1;i<=a;i++) cin>>st[i];
		sort(st+1,st+a+1,compare);
		for(int i=1;i<=a;i++) cout<<st[i]<<endl;
		while(b--)
		{
			cin>>t;
			int k=lower_bound(st+1,st+a+1,t)-st;//大于或等于t的第一个位置
			if(st[k]==t) cout<<t<<" found at "<<k<<endl;
			else cout<<t<<"not found"<<endl;
		}
	}
	return 0;
}
