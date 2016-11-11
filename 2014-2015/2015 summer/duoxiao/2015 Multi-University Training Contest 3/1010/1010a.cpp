#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define Max 500010
vector<int> edge[Max];
int w[Max],ans[Max],n;
void dfs(int a)
{
    ans[a]=1;
    int len=edge[a].size();
    for(int i=0;i<len;i++)
    {
        int v=edge[a][i];
        if(!ans[v]) dfs(v);
        ans[a]+=ans[v];
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            edge[i].clear();
        }
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(w[a]<w[b]) edge[a].push_back(b);
            else edge[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(ans[i]) continue;
            dfs(i);
        }
        int maxx=-1;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,ans[i]);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
