#include <string.h>
#include <iostream>
using namespace std;
int mp[10][10],k,n,cnt;
int vis[10];
void dfs(int f,int num)
{
    if(num==k) {cnt++;return ;}
    if(f>n) return ;
    for(int i=1;i<=n;i++)
    {
        if(mp[i][f]&&!vis[i])
        {
            vis[i]=1;
            dfs(f+1,num+1);
            vis[i]=0;
        }
    }
    dfs(f+1,num);
    return ;
}
int main()
{
    char t;
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1) break;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>t;
                if(t=='#') mp[j][i]=1;
            }
        }
        dfs(1,0);
        cout<<cnt<<endl;
    }
    return 0;
}
