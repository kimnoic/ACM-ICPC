#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,q;
#define Max 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int val[Max];
struct node{
    int l,r;
    long long sum,add;
    int mid(){
        return (l+r)/2;
    }
}p[Max*4];
void pushup(int rt){
    p[rt].sum=p[rt*2].sum+p[rt*2+1].sum;
}
void pushdown(int rt,int m){
    if(p[rt].add){
        p[rt*2].add+=p[rt].add;
        p[rt*2+1].add+=p[rt].add;
        p[rt*2].sum+=p[rt].add*(m-(m>>1));
        p[rt*2+1].sum+=p[rt].add*(m>>1);
        p[rt].add=0;
    }
}
void update(int c,int l,int r,int rt){
    if(p[rt].l==l&&p[rt].r==r){
        p[rt].add+=c;
        p[rt].sum+=(r-l+1)*c;
        return ;
    }
    if(p[rt].l==p[rt].r) return ;
    pushdown(rt,p[rt].r-p[rt].l+1);
    int mid=p[rt].mid();
    if(r<=mid){
        update(c,l,r,rt*2);
    }
    else if(l>mid){
        update(c,l,r,rt*2+1);
    }
    else {
        update(c,l,mid,rt*2);
        update(c,mid+1,r,rt*2+1);
    }
    pushup(rt);
}
void build(int l,int r,int rt){
    p[rt].l=l;p[rt].r=r;p[rt].add=0;
    p[rt].sum=0;
    if(l==r){
        p[rt].sum=val[l];
        return ;
    }
    int m=p[rt].mid();
    build(lson);
    build(rson);
    pushup(rt);
}
long long query(int l,int r,int rt){
    if(l==p[rt].l&&r==p[rt].r){
        return p[rt].sum;
    }
    pushdown(rt,p[rt].r-p[rt].l+1);
    int m=p[rt].mid();

    if(r<=m) return query(l,r,rt*2);
    else if(l>m) return query(l,r,rt*2+1);
    else {
        return query(l,m,rt*2)+query(m+1,r,rt*2+1);
    }

}
char t;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        scanf("%d",&val[i]);
    }
    build(1,n,1);
    for(int i=1;i<=q;i++){
        scanf(" %c",&t);
        if(t=='Q'){
            int a,b;
            scanf("%d%d",&a,&b);
            //cout<<a<<b<<endl;
            cout<<query(a,b,1)<<endl;
        }
        else {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(c,a,b,1);
        }
    }
    return 0;
}
