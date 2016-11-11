#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::sort;

struct line
{
    int end,next;
}s[2000001];

struct vertice
{
    int weight,num;
}a[1000001];

int begin[1000001],f[1000001];

bool cmp(vertice i,vertice j)
{
    return i.weight>j.weight;
}

int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        t=0;
        memset(begin,-1,sizeof(begin));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].weight);
            a[i].num=i;
        }
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            t++;
            s[t].end=y;
            s[t].next=begin[x];
            begin[x]=t;
            t++;
            s[t].end=x;
            s[t].next=begin[y];
            begin[y]=t;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            int x,k;
            x=a[i].num;
            k=begin[x];
            while(k!=-1)
            {
                f[x]+=f[s[k].end];
                k=s[k].next;
            }
            f[x]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(f[i]>ans)
                ans=f[i];
        printf("%d\n",ans);
    }
    return 0;
}
