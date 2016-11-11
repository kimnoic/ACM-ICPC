#include <iostream>
#include <stdio.h>
#include <string.h>
#define Max 50002
#define RR(X) ((X)<<1)+1
#define LL(X) (X)<<1

using namespace std;

using namespace std;
int solider[Max];

struct node
{
    int l,r,number;
}tree[Max*4];


int build(int l,int r,int n)
{    tree[n].l=l;
     tree[n].r=r;
     if(l==r)
        {         return tree[n].number=solider[l];     };
     int mid=(l+r)>>1;     return tree[n].number=build(l,mid,LL(n))+build(mid+1,r,RR(n));
}

int update(int l,int r,int n,int num)
{     if(tree[n].l==l && tree[n].r==r){  return tree[n].number+=num;  }
      if(l>=tree[RR(n)].l)         return tree[n].number=tree[LL(n)].number+update(l,r,RR(n),num);
      else if(r<=tree[LL(n)].r)         return tree[n].number=update(l,r,LL(n),num)+tree[RR(n)].number;
      else return tree[n].number=update(l,tree[LL(n)].r,LL(n),num)+update(tree[RR(n)].l,r,RR(n),num);
}

/*int query(int l,int r,int step)
{
    if(tree[step].r==r&&tree[step].l==l) return tree[step].number;
    int ls=step<<1;
    int rs=step<<1+1;
    if(r<=tree[ls].r) return query(l,r,ls);
    else if(l>=tree[rs].l) return query(l,r,rs);
    else return query(l,tree[ls].r,ls)+query(tree[rs].l,r,rs);
}*/

int query(int l,int r,int n)
{    if(tree[n].l==l && tree[n].r==r){         return tree[n].number;     }
     if(r<=tree[LL(n)].r)         return query(l,r,LL(n));
     else if(l>=tree[RR(n)].l)         return query(l,r,RR(n));
     else { return query(l,tree[LL(n)].r,LL(n))+query(tree[RR(n)].l,r,RR(n));     }
}

int main()
{
    int t;
    int n;
    cin>>t;
    int k=1;
    while(t--)
    {
        printf("Case %d:\n",k);k++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&solider[i]);
    build(1,n,1);
    char s[10];
    while(1)
    {
        scanf("%s",&s);
        if(s[0]=='E') break;
    int a,b;
    cin>>a>>b;
    if(s[0]=='Q') printf("%d\n",query(a,b,1));
    else if(s[0]=='A')
    {
        update(a,a,1,b);
    }
    else if(s[0]=='S')
    {
        update(a,a,1,-b);
    }
    }
    }
    return 0;
}
