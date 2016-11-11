#include <bits/stdc++.h>
using namespace std;
#define Max 500010
vector <int >p[Max];
int a[Max];
char b[Max];
int dep[Max];
int n,m;int v,h;
void dfs(int a,int step)
{
    dep[a]=step;
    int len=p[a].size();
    for(int i=0;i<len;i++)
    {
        dfs(p[a][i],step+1);
    }
    return ;
}
int k[30];
void f(int a,int step)
{
    if(step==h)
    {
        k[b[a]-'a'+1]++;
    }
    else
    {
        int len=p[a].size();
        for(int i=0;i<len;i++)
        {
            f(p[a][i],step+1);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        //cin>>a[i];
        p[a[i]].push_back(i);
    }
    scanf("%s",b+1);

    dfs(1,1);
    for(int i=1;i<=m;i++)
    {
        memset(k,0,sizeof(k));
        scanf("%d %d",&v,&h);
        int d=dep[v];
        if(h<=d)
        {
            printf("Yes\n");
            continue;
        }
        f(v,d);
        int flag=0;
        for(int i=1;i<=26;i++)
        {
            if(k[i]%2==1) flag++;
            if(flag>=2) break;
        }
        if(flag>=2) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
