#include <stdio.h>
#define RR(X) ((X)<<1)+1
#define LL(X) (X)<<1
#define Max 200005
#include <string.h>
#include <iostream>
using namespace std;


struct A
{     int l,r,number;
}xd[4*Max];
int student[Max];

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int build(int l,int r,int n)
{    xd[n].l=l;
     xd[n].r=r;
     if(l==r)
        {         return xd[n].number=student[l];     };
     int mid=(l+r)>>1;     return xd[n].number=max(build(l,mid,LL(n)),build(mid+1,r,RR(n)));
}

int query(int l,int r,int n)
{    if(xd[n].l==l && xd[n].r==r){         return xd[n].number;     }
     if(r<=xd[LL(n)].r)         return query(l,r,LL(n));
     else if(l>=xd[RR(n)].l)         return query(l,r,RR(n));
     else { return max(query(l,xd[LL(n)].r,LL(n)),query(xd[RR(n)].l,r,RR(n)));     }
}

int updata(int l,int r,int n,int num)
{     if(xd[n].l==l && xd[n].r==r){  return xd[n].number=num;  }
      if(l>=xd[RR(n)].l)         return xd[n].number=max(xd[LL(n)].number,updata(l,r,RR(n),num));
      else if(r<=xd[LL(n)].r)         return xd[n].number=max(updata(l,r,LL(n),num),xd[RR(n)].number);
      else return xd[n].number=max(updata(l,xd[LL(n)].r,LL(n),num),updata(xd[RR(n)].l,r,RR(n),num));
}
int main()
{
        int n,m;
        while(cin>>n>>m)
        {
        for (int i=1;i<=n;i++)             scanf("%d",&student[i]);
        build(1,n,1);
        char t[10];
        int a,b;
        for(int i=1;i<=m;i++)
            {scanf("%s%d%d",t,&a,&b);
        if(t[0]=='Q') printf("%d\n",query(a,b,1));
        else updata(a,a,1,b);
            }
        }
}

