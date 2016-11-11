#include <bits/stdc++.h>
using namespace std;
long long w,m;
int flag;
void dfs(long long b,long long c)
{
	if(c==m)
	{
		flag=1;
		return ;
	}
    if(flag) return ;
	if(abs(b)<=m*w)
	{
		dfs(b*w,c+b);
		dfs(b*w,c-b);
		dfs(b*w,c);
	}
	return ;
}
int main()
{
	flag=0;
	cin>>w>>m;
	if(w<=3)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    dfs(1,0);
    if(flag) cout<<"YES";
    else cout<<"NO";
	return 0;
}
