#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 200010
struct tree
{
    int left,right,num;
}p[Max*4];
int val[Max];
int n,m;
void build(int l,int r,int rt)
{
    p[rt].left=l;
    p[rt].right=r;
    if(l==r)
    {
        p[rt].num=val[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    p[rt].num=max(p[rt*2].num,p[rt*2+1].num);
}
int query(int l,int r,int rt)
{
    if(l<=p[rt].left&&r>=p[rt].right)
        return p[rt].num;
    if(l>p[rt].right||r<p[rt].left) return -1;
    return max(query(l,r,rt*2),query(l,r,rt*2+1));
}
void update(int pp,int va,int rt)
{
    if(p[rt].left==p[rt].right)
    {
        p[rt].num=va;
        return ;
    }
    int mid=(p[rt].left+p[rt].right)/2;
    if(pp<=mid)
        update(pp,va,rt*2);
    else
        update(pp,va,rt*2+1);
    p[rt].num=max(p[rt*2].num,p[rt*2+1].num);
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) scanf("%d",&val[i]);//cin>>val[i];
        build(1,n,1);
        while(m--)
        {
            char t[233];int le,ri;int pos,v;
            //scanf("%c",&t);
            scanf("%s",t);
            //cin>>le>>ri;
            scanf("%d%d",&le,&ri);
            if(t[0]=='Q')
            {
                cout<<query(le,ri,1)<<endl;
            }
            else
            {
                update(le,ri,1);
            }
        }
    }
    return 0;
}
