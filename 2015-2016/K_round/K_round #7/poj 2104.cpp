#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int maxn = 100010;
const int M = maxn*30;
int n,q,m,tot;
int a[maxn],t[maxn],T[maxn],lson[M],rson[M],c[M];
void init(){
    for(int i=1;i<=n;i++){
        t[i]=a[i];
    }
    sort(t+1,t+n+1);
    m=unique(t+1,t+n+1)-t-1;
    //cout<<m<<endl;
}
int build(int l,int r){
    int root=tot++;
    c[root]=0;
    if(l!=r){
        int mid=(l+r)>>1;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int Hash(int x){
    return lower_bound(t+1,t+m+1,x)-t;
}
int update(int root,int pos,int val){
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(pos<=mid){
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];
            root=lson[root];
            r=mid;
        }
        else {
            rson[newroot]=tot++;
            lson[newroot]=lson[root];
            newroot=rson[newroot];
            root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(c[lson[left_root]]-c[lson[right_root]]>=k){
            r=mid;
            left_root=lson[left_root];
            right_root=lson[right_root];
        }
        else {
            l=mid+1;
            k-=c[lson[left_root]]-c[lson[right_root]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
int main(){
    while(~scanf("%d%d",&n,&q)){
        tot=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);//"cin>>a[i];
        init();
        T[n+1]=build(1,m);
        for(int i=n;i>=1;i--){
            int pos=Hash(a[i]);
            T[i]=update(T[i+1],pos,1);
        }
        while(q--){
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            //cin>>l>>r>>k;
            printf("%d\n",t[query(T[l],T[r+1],k)]);//<<endl;
        }
    }
    return 0;
}
