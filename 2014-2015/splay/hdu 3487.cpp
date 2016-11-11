#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int N = 300002;
const int INF = 1e9;
const int MOD = 1000000;



struct Tnode{
    int c, lc, rc, fa, s, sign;
} T[N];
void init(){
    memset(T,0,sizeof(T));
}
int root;int cnt;


void Update(int f, int x, int flag){
    if (x) T[x].fa = f;
    if (f){
        if (flag) T[f].lc = x; else T[f].rc = x;
        T[f].s = T[T[f].lc].s + T[T[f].rc].s + 1;
    }
}

void Push(int f){
    if (!T[f].sign) return;
    int l = T[f].lc, r = T[f].rc;
    T[f].sign = 0;
    T[l].sign ^= 1, T[r].sign ^= 1;
    Update(f, l, 0), Update(f, r, 1);
}

void Up(int x){
    int y, z;
    y = T[x].fa; z = T[y].fa;
    Push(z); Push(y); Push(x);
    if (T[y].lc == x){
        Update(y, T[x].rc, 1);
        Update(x, y, 0);
        Update(z, x, T[z].lc == y);
    }else{
        Update(y, T[x].lc, 0);
        Update(x, y, 1);
        Update(z, x, T[z].lc == y);
    }
}
int n,m;
void Splay(int x, int &t){
    int y, z, limit;
    y = T[x].fa; z = T[y]. fa; limit = T[t].fa;
    //cout<< x <<"  "<<y<<"  "<<z<<endl;
    while (y != limit){
        if (z != limit && (T[y].lc == x) == (T[z].lc == y)) {Up(y);}
        Up(x);y = T[x].fa; z = T[y].fa;
    }
    t = x; Push(t);
}

int Build(int l, int r){
    if (l > r) return 0;
    if (l == r){
        Update(l, 0, 0);
        Update(l, 0, 1);
        T[l].sign = 0;
        return l;
    }
    int mid = l + r >> 1;
    Update(mid, Build(l, mid - 1), 1), Update(mid, Build(mid + 1, r), 0);
    T[mid].sign = 0;
    return mid;
}

void Delete(int &f){
    Push(f);
    int l = T[f].lc, r = T[f].rc;
    T[l].fa = T[r].fa = 0;
    if (!l || !r){f = l + r; return;}
    int x = l;
    while (1){
        Push(x);
        if (!T[x].rc) break;
        x = T[x].rc;
    }
    Splay(x, l);
    Update(x, r, 0);
    f = x;
}

int findk(int e,int k){
    if(k<=T[T[e].lc].s){
        return findk(T[e].lc,k);
    }
    else if(k==T[T[e].lc].s+1){
        return e;
    }
    else return findk(T[e].rc,k-T[T[e].lc].s-1);
}
int val[N];

int l,r,v;
char t[10];
void pr(int u,int f){
    cnt++;
    if(!T[u].sign){

            if(f==1){
                if(T[u].lc)
                pr(T[u].lc,f);
                if(cnt!=n)
                printf("%d ",u);
                else printf("%d",u);
                if(T[u].rc)
                pr(T[u].rc,f);
            }
            else{
                if(T[u].rc) pr(T[u].rc,f);
                if(cnt!=n)
                printf("%d ",u);
                else printf("%d",u);
                if(T[u].lc) pr(T[u].lc,f);
            }
    }
    else {
            f^=1;
            if(!f){
                if(T[u].rc) pr(T[u].rc,f);
                if(cnt!=n)
                printf("%d ",u);
                else printf("%d",u);
                if(T[u].lc) pr(T[u].lc,f);
            }
            else{
                if(T[u].lc)
                pr(T[u].lc,f);
                if(cnt!=n)
                printf("%d ",u);
                else printf("%d",u);
                if(T[u].rc)
                pr(T[u].rc,f);
            }
    }
}
int main(){
    while(cin>>n>>m){
        if(n==-1&&m==-1) break;
        init();
        /*for(int i=1;i<=n;i++){
            T[i].c=T[i].fa=T[i].lc=T[i].rc=T[i].s=T[i].sign=0;
        }*/
        Build(1,n);
        root=0;
        Splay((1+n)/2,root);

        T[n+1].lc=root;
        T[root].fa=n+1;
        root=n+1;
        /*T[0].rc=n+1;
        T[n+1].fa=0;*/
        for(int i=0;i<=n+1;i++) cout<<i<<" "<<T[i].lc<<" "<<T[i].rc<<endl;
        for(int i=1;i<=m;i++){
            cin>>t;
            if(t[0]=='C'){
                scanf("%d%d%d",&l,&r,&v);
                int ll=findk(root,l-1),rr=findk(root,r+1);
                Splay(ll,root);
                Splay(rr,T[root].rc);
                int q=T[T[root].rc].lc;T[T[root].rc].s-=T[q].s;
                T[T[root].rc].lc=0;
                T[root].s-=T[q].s;
                int k=findk(root,v);
                Splay(k,root);
                int w=T[k].rc;
                while(T[w].lc!=0){
                    w=T[w].lc;
                }
                Splay(w,T[root].rc);
                T[w].lc=q;
                T[q].fa=w;
                T[w].s+=T[q].s;
                T[k].s+=T[q].s;
                //Splay(q,root);
            }
            else {
                scanf("%d%d",&l,&r);
                int ll=findk(root,l-1);
                int rr=findk(root,r+1);
                //cout<<ll<<" "<<rr<<endl;
                Splay(ll,root);
                //for(int i=1;i<=n;i++) cout<<i<<" "<<T[i].s<<endl;
                cout<<root<<endl;
                Splay(rr,T[root].rc);
                T[T[T[root].rc].lc].sign^=1;

            }
            pr(root,1);
            cout<<endl;
            //pr(root);cout<<endl;
        }
        pr(root,1);
        cout<<endl;
    }
    return 0;
}
