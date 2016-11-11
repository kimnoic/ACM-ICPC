#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
int T;
#define Max 50010
struct tree{
    int l,r,sum;
}p[Max*4];
int val[Max];
void build(int l,int r,int rt){
    p[rt].l=l;p[rt].r=r;
    if(l==r){
        p[rt].sum=val[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    p[rt].sum=p[rt*2+1].sum+p[rt*2].sum;
}

int query(int l,int r,int rt){
    if(p[rt].l==l&&p[rt].r==r){
        return p[rt].sum;
    }
    int mid=(p[rt].l+p[rt].r)/2;
    if(r<=p[rt*2].r){
        return query(l,r,rt*2);
    }
    else if(l>=p[rt*2+1].l){
        return query(l,r,rt*2+1);
    }
    else return query(l,mid,rt*2)+query(mid+1,r,rt*2+1);
}
void update(int rt,int num,int k){
    if(p[rt].l==p[rt].r){
        p[rt].sum+=num;
        return ;
    }
    int mid=(p[rt].l+p[rt].r)/2;
    if(k<=mid){
        update(rt*2,num,k);
    }
    else update(rt*2+1,num,k);
    p[rt].sum=p[rt*2].sum+p[rt*2+1].sum;
}
int n;
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) {
            scanf("%d",&val[i]);
        }
        build(1,n,1);
        printf("Case %d:\n",++_case);
        char t[5];
        while(scanf("%s",t)){
            if(t[0]=='E') break;
            if(t[0]=='Q'){
                int a,b;
                scanf("%d%d",&a,&b);
                int res=query(a,b,1);
                printf("%d\n",res);
            }
            else if(t[0]=='A'){
                int a,b;
                scanf("%d%d",&a,&b);
                update(1,b,a);
            }
            else if(t[0]=='S'){
                int a,b;
                scanf("%d%d",&a,&b);
                update(1,-b,a);

            }
        }
    }
    return 0;
}
