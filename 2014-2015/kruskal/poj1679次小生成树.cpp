#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define Max 102
#define Maxx 5002

struct edge
{
    int u,v;
    int w;
}edges[Maxx];
int n,m,p[Max],sum;


bool cmp(edge a,edge b)
{
    if(a.w<b.w) return true;
    return false;
}

void build()
{
    for(int x=1;x<=n;x++)
        p[x]=x;
}

int look(int x)
{
    if(x!=p[x])
        p[x]=look(p[x]);
    return p[x];
}
bool uni;
void kruskal()
{
    int x,y;
    int a[Max],numm,k=0;
    build();
    sort(edges,edges+ m,cmp);
    sum=0;
    for(int i=0;i<m;i++)
    {
        x = look(edges[i].u);
        y = look(edges[i].v);
        if(x!=y)
        {
            p[y]=x;
            sum+=edges[i].w;
            a[k++]=i;
        }
    }
    numm=k;
    uni=true;
    int r,num;
    for(k=0;k<numm;k++)
    {
        build();
        r=0;
        num=0;
        for(int i=0;i<m;i++)
        {
            if(i==a[k]) continue;
            x=look(edges[i].u);
            y=look(edges[i].v);
            if(x!=y)
            {
                p[y]=x;
                r+=edges[i].w;
                num++;
            }
        }
        if(num!=numm) continue;
        if(r==sum)
        {
            uni=false;
            return;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        kruskal();
        if(!uni) printf("Not Unique!\n");
        else printf("%d\n",sum);
    }
    return 0;
}
