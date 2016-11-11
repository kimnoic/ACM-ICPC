#include <iostream>
#include <stdio.h>
#include <string.h>
#define Max 200002
#define RR(X) ((X)<<1)+1
#define LL(X) (X)<<1

using namespace std;
int student[Max]={};

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
struct node
{
    int l,r,number;
}tree[Max*4];

int build (int l,int r,int step)
{
    tree[step].l=l;
    tree[step].r=r;
    if(l==r)  return tree[step].number=student[l];
    int mid=(l+r)>>1;
    int ls=step<<1;
    int rs=step<<1+1;
    return tree[step].number=max(build(l,mid,ls),build(mid+1,r,rs));
}

int query(int l,int r,int step)
{
    if(tree[step].r==r&&tree[step].l==l) return tree[step].number;
    int ls=step<<1;
    int rs=step<<1+1;
    if(r<=tree[ls].r) return query(l,r,ls);
    else if(l>=tree[rs].l) return query(l,r,rs);
    else return max(query(l,tree[ls].r,ls),query(tree[rs].l,r,rs));
}



/*int update(int l,int r,int step,int c)
{
    if(tree[step].l==l&&tree[step].r==r) return tree[step].number=c;
    int ls=step<<1;
    int rs=step<<1+1;
    if(l>=tree[rs].l)
        return  tree[step].number=max(tree[ls].number,update(l,r,rs,c));
    else if(r<=tree[ls].r)
        return tree[step].number=max(tree[rs].number,update(l,r,ls,c));
    else return  tree[step].number=max(update(l,tree[ls].r,ls,c),update(tree[rs].l,r,rs,c));
}*/

int update(int l,int r,int n,int num)
{     if(tree[n].l==l && tree[n].r==r){  return tree[n].number=num;  }
      if(l>=tree[RR(n)].l)         return tree[n].number=max(tree[LL(n)].number,update(l,r,RR(n),num));
      else if(r<=tree[LL(n)].r)         return tree[n].number=max(update(l,r,LL(n),num),tree[RR(n)].number);
      else return tree[n].number=max(update(l,tree[LL(n)].r,LL(n),num),update(tree[RR(n)].l,r,RR(n),num));
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(student,0,sizeof(student));
    for(int i=1;i<=n;i++) scanf("%d",&student[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++)
    {
        char tt;
        cin>>tt;
        int a,b;
        scanf("%d%d",&a,&b);
        if(tt=='Q') printf("%d\n",query(a,b,1));
        else update(a,a,1,b);
    }
    return 0;
}
