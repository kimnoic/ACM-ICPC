#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 8010
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
int col[Max];
int res[Max];
struct tree{
    int l,r,c;
    int mid(){
        return (l+r)/2;
    }
}p[Max*4];
void build(int l,int r,int rt){
    p[rt].l=l;
    p[rt].r=r;
    if(l==r){
        p[rt].c=-1;
        return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
}
void pushdown(int rt){
    if(p[rt].c!=-1){
        p[rt*2].c=p[rt].c;
        p[rt*2+1].c=p[rt].c;
        p[rt].c=-1;
    }
}
void update(int l,int r,int c,int rt){
    if(c==p[rt].c){
        return ;
    }
    else if(l<=p[rt].l&&r>=p[rt].r){
        p[rt].c=c;
        return ;
    }
    pushdown(rt);
    int m=(l+r)/2;
    if(r<=m){
        update(l,r,c,rt*2);
    }
    else if(l>=m+1){
        update(l,r,c,rt*2+1);
    }
    else {
        update(l,r,c,rt*2);update(l,r,c,rt*2+1);
    }
    if(p[rt*2].c==p[rt*2+1].c&&p[rt*2].c!=-1){
        p[rt].c=p[rt*2].c;
    }
}
void query(int rt){
    if(p[rt].c!=-1){
        for(int i=p[rt].l;i<=p[rt].r;i++){
            col[i]=p[i].c;
        }
    }
    if(p[rt].l==p[rt].r) return ;
    query(rt*2);
    query(rt*2+1);
}
int n;

int a,b,c;
int main(){
    while(~scanf("%d",&n)){
        memset(col,0,sizeof(c));
        memset(res,0,sizeof(res));
        build(1,8000,1);
        while(n--){
            scanf("%d%d%d",&a,&b,&c);
            update(a,b-1,c,1);
        }
        int flag=-1;
        for(int i=1;i<=8000;i++){
            if(col[i]!=-1){
                if(col[i]!=flag){
                    flag=col[i];
                    res[flag]++;
                }
            }
            else flag=-1;
        }
        for(int i=1;i<=8000;i++){
            if(res[i]){
                printf("%d %d\n",i,res[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
