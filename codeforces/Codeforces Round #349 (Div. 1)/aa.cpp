#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define pi acos(-1)
#define eps 1e-13
#define mod 10000007
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,top;
char c[10005];
int path[10005],ans[20005],v[10005][3],mark[10005][3];
string q[20005];
int get(int x,int y)
{
    if(y>n)return 0;
    int H=0;
    for(int i=x;i<=y;i++)
        H=H*27+c[i]-'a'+1;
    return H;
}
int dfs(int x,int K,int Last,int d)
{
    if(x==n+1)return 1;
    if(x>=n)return 0;
    if(mark[x][d])return mark[x][d];
    mark[x][d]=-1;
    for(int k=1;k<=2;k++)
    {
        int t=v[x][k];
        if(Last!=t)
        {
            path[K]=t;
            if(dfs(x+k+1,K+1,t,k)==1)
            {
                mark[x][d]=1;
                ans[t]=1;
            }
        }
    }
    return mark[x][d];
}
int main()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    for(int i=1;i<=n-1;i++)v[i][1]=get(i,i+1);
    for(int i=1;i<=n-2;i++)v[i][2]=get(i,i+2);
    for(int i=5;i<=n;i++)
        dfs(i+1,1,-1,0);
    for(int i=1;i<=n;i++)
        for(int k=1;k<=2;k++)
            if(i+k<=n&&ans[v[i][k]])
            {
                string s="";
                for(int t=0;t<=k;t++)
                    s+=c[i+t];
                ans[v[i][k]]=0;
                q[++top]=s;
            }
    sort(q+1,q+top+1);
    cout<<top<<endl;
    for(int i=1;i<=top;i++)
        cout<<q[i]<<endl;
    return 0;
}
