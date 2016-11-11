#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Max 100010
struct pt
{
    int l,r,c,id,flag,pos;
}p[Max];
pt q[Max];
int T;
using namespace std;
int n;
int vis[Max],b[Max];
bool cmp(pt a,pt b)
{
    if(a.c==b.c) return a.l<b.l;
    return a.c<b.c;
}
bool cp(pt a,pt b)
{
    return a.pos<b.pos;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int top=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i].l);
            p[i].id=i;
            vis[i]=0;
            p[i].flag=0;
            b[i]=0;
        }
        vis[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i].r);
            p[i].c=p[i].r-p[i].l;
        }
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=p[i].l;j<=p[i].r;j++)
            {
                if(!vis[j])
                {
                    p[i].flag=1;
                    p[i].pos=j;
                    vis[j]=p[i].id;
                    break;
                }
            }
        }
        int sum=0;
        for(int i=0;i<=n;i++)
        {
            if(!vis[i]) continue;
            if(sum<p[i].l||sum>p[i].r) {vis[i]=0;continue;}
            sum++;
            b[p[i].id]=1;
        }
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            printf("%d ",p[i].id);
        }
        for(int i=1;i<=n;i++)
        {
            if(!b[i])
                printf("%d ",i);
        }
        cout<<endl;
        /*
        for(int i=1;i<=n;i++)
        {
            if(p[i].flag)
            {
                q[++top].l=p[i].l;
                q[top].l=p[i].l;
                q[top].r=p[i].r;
                q[top].c=p[i].c;
                q[top].pos=p[i].pos;
                q[top].id=p[i].id;
                q[top].flag=p[i].flag;
            }
        }
        sort(q+1,q+top+1,cp);
        int cur=0;
        for(int i=1;i<=top;i++)
        {
            if(cur>=q[i].l&&cur<=q[i].r)
            {
                cur++;
                q[i].flag=1;
            }
        }
        cout<<cur<<endl;
        for(int i=1;i<=top;i++)
        {
            if(q[i].flag)
            printf("%d ",q[i].id);
        }
        for(int i=1;i<=n;i++)
        {
            if(p[i].flag==0)
            {
                printf("%d ",p[i].id);
            }
        }
        for(int i=1;i<=top;i++)
        {
            if(q[i].flag==0)
            {
                printf("%d ",q[i].id);
            }
        }
        cout<<endl;
        */
    }
    return 0;
}
/*
3
8
3 3 2 0 5 0 3 6
4 5 2 7 7 6 7 6
*/
