#include <iostream>
#include <stdio.h>
#define L(a) (a<<1)
#define R(a) (L(a)+1)
#define N 100001
#define ll long long
using namespace std;

long long num;
int n,m,l,r,kind;
struct node{
    int l, r, id;
    bool same;
    int siz(){return r-l+1;}
    long long sum,col,la;
}tree[N<<4];

void build(int l,int r,int id)
{
    tree[id].l=l,tree[id].r=r;
    tree[id].sum=0;
    tree[id].la=0;
    tree[id].col=-1;
    tree[id].same=false;
    if(l==r)
    {
        tree[id].col = l;tree[id].same =true;
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,L(id));build(mid+1,r,R(id));
}
void push1(int id)
{
    if(tree[id].l==tree[id].r)return ;
    if(tree[id].la)
    {
        tree[L(id)].la+=tree[id].la;
        tree[R(id)].la+=tree[id].la;
        tree[L(id)].sum+=tree[L(id)].siz()*tree[id].la;
        tree[R(id)].sum+=tree[R(id)].siz()*tree[id].la;
        tree[id].la= 0;
    }
    if(tree[id].col>=0){
        tree[L(id)].col = tree[R(id)].col = tree[id].col;
    }
}
void push2(int id)
{
    if(tree[L(id)].col>=0&&tree[L(id)].col==tree[R(id)].col)
    {
        tree[id].col = tree[L(id)].col;
        tree[id].same=true;
    }
    else
        {
            tree[id].col = -1;
            tree[id].same=false;
        }
    tree[id].sum = tree[L(id)].sum+tree[R(id)].sum;
}
long long abs(long long a)
{
    if(a>=0) return a;
    else return -a;
}
void updata(int l, int r, int id, int col)
{
    push1(id);
    if(l==tree[id].l&&tree[id].r==r && tree[id].same){
        tree[id].sum+= tree[id].siz() * abs(col-tree[id].col);
        tree[id].la+= abs(col-tree[id].col);
        tree[id].col = col;
        return ;
    }
    int mid =(tree[id].l+tree[id].r)>>1;
    if(mid<l)
        updata(l,r,R(id),col);
    else if(r<=mid)
        updata(l,r,L(id),col);
    else {
        updata(l,mid,L(id),col);
        updata(mid+1,r,R(id),col);
    }
    push2(id);
}
long long countc(int l, int r, int id)
{
    push1(id);
    if(l==tree[id].l && tree[id].r==r)
        return tree[id].sum;
    int mid = (tree[id].l+tree[id].r)>>1;
    if(mid<l) return countc(l,r,R(id));
    else if(r<=mid) return countc(l,r,L(id));
    else return countc(l,mid,L(id))+countc(mid+1,r,R(id));
}
int main()
{
    while(cin>>n>>m)
    {
            build(1,n,1);
            while(m--)
            {
            scanf("%d %d %d",&kind,&l,&r);
            if(kind==1)
            {
                scanf("%lld",&num);
                updata(l,r,1,num);
            }
            else printf("%lld\n",countc(l,r,1));
            }
    }
    return 0;
}
