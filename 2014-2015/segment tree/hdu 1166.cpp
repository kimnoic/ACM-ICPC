#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define Max  50010
struct line
{
    int left,right;
    int sum;
}p[Max*4];
int val[Max],n;
void build(int l,int r,int rt)
{
    p[rt].left=l;p[rt].right=r;
    if(l==r)
    {
        p[rt].sum=val[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    p[rt].sum=p[rt*2].sum+p[rt*2+1].sum;
}
int query(int l,int r,int rt)
{
    if(l==p[rt].left&&r==p[rt].right)
    {
        return p[rt].sum;
    }
    int mid=(p[rt].left+p[rt].right)/2;
    if(r<=p[rt*2].right)
    {
        return query(l,r,rt*2);
    }
    else if(l>=p[rt*2+1].left)
    {
        return query(l,r,rt*2+1);
    }
    else
    {
        return query(l,mid,rt*2)+query(mid+1,r,rt*2+1);
    }
}
void update(int q,int num,int rt)
{
    if(p[rt].left==p[rt].right)
    {
        p[rt].sum+=num;
        return ;
    }
    else
    {
        int mid=(p[rt].left+p[rt].right)/2;
        if(q<=mid)
        {
            update(q,num,rt*2);
        }
        else update(q,num,rt*2+1);
        p[rt].sum=p[rt*2].sum+p[rt*2+1].sum;
    }
}
int main()
{
    int T;
    cin>>T;
    int _case=0;
    while(T--)
    {
        cin>>n;
        cout<<"Case "<<++_case<<":"<<endl;
        for(int i=1;i<=n;i++) cin>>val[i];
        build(1,n,1);

        char t[233];
        int a,b;
        while(~scanf("%s",t))
        {
            if(t[0]=='E') break;
            else if(t[0]=='Q')
            {
                cin>>a>>b;
                int t=query(a,b,1);
                cout<<t<<endl;
            }
            else if(t[0]=='A')
            {
                cin>>a>>b;
                update(a,b,1);
            }
            else if(t[0]=='S')
            {
                cin>>a>>b;
                update(a,-b,1);
            }
        }
    }
    return 0;
}
