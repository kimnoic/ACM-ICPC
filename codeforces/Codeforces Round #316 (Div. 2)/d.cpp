#include <bits/stdc++.h>
using namespace std;
#define Max 500010
vector <int >p[Max];
vector <int >d[Max];
int a[Max];
char b[Max];
int dep[Max];
int n,m;int v,h,dd;
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
int fi(int t,int step)
{
    if(step==dd) return t;
    else return fi(a[t],step-1);
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
    for(int i=1;i<=n;i++)
    {
        d[dep[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        memset(k,0,sizeof(k));
        cin>>v>>h;dd=dep[v];
        int len=d[h].size();
        if(h<=dd)
        {
            printf("Yes\n");
            continue;
        }
        for(int j=0;j<len;j++)
        {
            if(fi(d[h][j],h)==v) k[b[d[h][j]]-'a'+1]++;
        }
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
