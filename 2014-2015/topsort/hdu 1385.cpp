#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 522
int mp[Max][Max],vis[Max],deg[Max],n,m;
void init()
{
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    memset(deg,0,sizeof(deg));
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(a==b) continue;
        if(!mp[a][b])
        {
            deg[b]++;
            mp[a][b]=1;
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        init();
        int top=0;
        int pos;
        while(top<n)
        {
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==0&&deg[i]==0)
                {
                    pos=i;
                    break;
                }
            }
            int i=pos;
            top++;
            if(top!=n)
            cout<<i<<" ";
            else cout<<i;
            vis[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]) deg[j]--;
            }
        }
        cout<<endl;
    }
    return 0;
}
