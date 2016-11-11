#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int maxn=20000;
const int mod=1000000007;
vector<pair<int,int> >tree[maxn<<2];
map<int,int>mp;
int mlen,a[maxn];
vector<pair<int,int> > getpre(int n){
    vector<pair<int,int> >res;
    for(int i=9;i>=0;--i)
        if(n&(1<<i)){
            res.push_back(make_pair(((n>>i)^1)<<4|i,1));
        }
    res.push_back(make_pair(n<<4,1));
    return res;
}
int cal(int x,int y){
    int xlen=x&0xf,ylen=y&0xf;
    if(xlen>ylen) {swap(x,y);swap(xlen,ylen);}
    x>>=4;y>>=4;
    int m=(ylen-xlen);
    x>>=m;
    mlen=xlen;
    return (x^y)<<4|ylen;
}
void PushUp(int rt){
    tree[rt].clear();
    mp.clear();
    int ls=rt<<1,rs=rt<<1|1,v,num,pos,tot=0;
    long long A,B;
    for(int i=0;i<(int)tree[ls].size();++i)
        for(int j=0;j<(int)tree[rs].size();++j){
            v=cal(tree[ls][i].first,tree[rs][j].first);
            A=tree[ls][i].second;B=tree[rs][j].second;
            num=A*(1<<mlen)%mod*B%mod;
            if(mp.find(v)==mp.end()){
                mp[v]=tot++;
                tree[rt].push_back(make_pair(v,num));
            }
            else{
                pos=mp[v];
                tree[rt][pos].second+=num;
                if(tree[rt][pos].second>=mod) tree[rt][pos].second-=mod;
            }
        }
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=getpre(a[l]);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    PushUp(rt);
}
void Update(int p,int l,int r,int rt,int v){
    if(l==r){
        tree[rt]=getpre(v);
        return ;
    }
    int m=(l+r)>>1;
    if(m>=p) Update(p,l,m,rt<<1,v);
    else Update(p,m+1,r,rt<<1|1,v);
    PushUp(rt);
}
int Query(int val){
    int ans=0,len;
    pair<int,int>pii;
    for(int i=0;i<(int)tree[1].size();++i){
        pii=tree[1][i];
        len=pii.first&0xf;
        if((pii.first>>4)==(val>>len)){
            ans+=pii.second;
            if(ans>=mod) ans-=mod;
        }
    }
    return ans;
}
int main(){
    char str[10];
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(1,n,1);
        int x,y;
        while(m--){
            scanf("%s%d",str,&x);
            if(str[0]=='Q')
                printf("%d\n",Query(x));
            else{
                scanf("%d",&y);
                Update(x+1,1,n,1,y);
            }
        }
    }
    return 0;
}
