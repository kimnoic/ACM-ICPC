#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>

#define max(i,j) (((i)>(j))?(i):(j))

using namespace std;

const int mod=1000000007,INF=1000000000;

int t,T,n,m,map[20][20],a[20][20],sum,tempans,ans;
int Be[101],cnt,cnte,q[101];
bool vi[101],mark[101];
int direc[4][2]={{0,1},{1,0},{0,-1},{-1,0}},v[10];

struct edge
{
    int to,next;
}e[10001];

void fill(int x,int y)
{
    for(int i=0;i<=3;i++)
    {
        int xx=x+direc[i][0],yy=y+direc[i][1];
        if(xx<1 || xx>n || yy<1 || yy>m)
            continue;
        if(map[xx][yy]==1)
        {
            map[xx][yy]=-1;
            fill(xx,yy);
        }
        else if(map[xx][yy]!=1)
            map[xx][yy]=-1;
    }
    return;
}

void fill2(int u,int x,int y)
{
    int xx,yy;
    map[x][y]=-1;
    for(int i=0;i<=3;i++)
    {
        int xx=x+direc[i][0],yy=y+direc[i][1];
        if(xx<1 || xx>n || yy<1 || yy>m)
            continue;
        if(map[xx][yy]==0)
        {
            ++cnt;
            if((xx+yy)%2==0)
                mark[cnt]=1;
            Be[cnt]=-1;
            e[++cnte].to=cnt;
            e[cnte].next=Be[u];
            Be[u]=cnte;
            e[++cnte].to=u;
            e[cnte].next=Be[cnt];
            Be[cnt]=cnte;
            fill2(cnt,xx,yy);
        }
    }
    return;
}

bool match(int u)
{
    int k=Be[u],d;
    while(k!=-1)
    {
        d=e[k].to;
        k=e[k].next;
        if(vi[d]==1)
            continue;
        vi[d]=1;
        if(q[d]==0 || match(q[d]))
        {
            q[d]=u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&T);
    char c;
    for(int t=1;t<=T;t++)
    {
        for(int i=0;i<=9;i++)
            v[i]=-1;
        sum=0;
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf(" %c",&c);
                if(c=='.')
                    a[i][j]=-1;
                else if(c>='0' && c<='9')
                {
                    a[i][j]=c-'0';
                    if(v[a[i][j]]==-1)
                        v[a[i][j]]=sum++;
                    a[i][j]=v[a[i][j]];
                }
            }
        for(int l=0;l<(1<<sum);l++)
        {
            tempans=0;
            memset(map,0,sizeof(map));
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(a[i][j]>=0 && ((l&(1<<a[i][j]))>0))
                        map[i][j]=1;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(map[i][j]==1)
                    {
                        map[i][j]=-1;
                        fill(i,j);
                        ++tempans;
                    }
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(a[i][j]>=0)
                        map[i][j]=-1;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(map[i][j]==0)
                    {
                        Be[1]=-1;
                        cnt=cnte=0;
                        ++cnt;
                        map[i][j]=-1;
                        memset(mark,0,sizeof(mark));
                        if((i+j)%2==0)
                            mark[1]=1;
                        fill2(1,i,j);
                        int temp=0;
                        memset(q,0,sizeof(q));
                        for(int k=1;k<=cnt;k++)
                            if(mark[k])
                            {
                                memset(vi,0,sizeof(vi));
                                temp+=match(k);
                            }
                        tempans+=cnt-temp;
                    }/**/
            if(tempans>ans)
                ans=tempans;
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
