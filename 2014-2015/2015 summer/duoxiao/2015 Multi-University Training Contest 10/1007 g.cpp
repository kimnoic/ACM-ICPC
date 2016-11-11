#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200002;
const int INF = 1e9;


struct Tnode{
    int c, lc, rc, fa , size;
} T[N];
int lsize(int p)
{
    if(T[p].lc) return T[T[p].lc].size;
    else return 0;
}
int rsize(int p)
{
    if(T[p].rc)
        return T[T[p].rc].size;
    else return 0;
}
int root;

void Update(int f, int x, int flag){
    if (x) T[x].fa = f;
    if (f){
        if (flag) T[f].lc = x; else T[f].rc = x;
    }
    T[x].size=lsize(x)+rsize(x)+1;
}
void Up(int x){
    int y, z;
    y = T[x].fa; z = T[y].fa;
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
void Splay(int x, int &t){
    int y, z, limit;
    y = T[x].fa; z = T[y]. fa; limit = T[t].fa;
    while (y != limit){
        if (z != limit && (T[y].lc == x) == (T[z].lc == y)) Up(y);
        Up(x); y = T[x].fa; z = T[y].fa;
    }
    t = x;
}
void Insert(int i){
    int f = root;
    while (1){
        if (T[f].c >= T[i].c){
            if (!T[f].lc){
                Update(f, i, 1);
                break;
            }else f = T[f].lc;
        }else{
            if (!T[f].rc){
                Update(f, i, 0);
                break;
            }else f = T[f].rc;
        }
    }
    Splay(i, root);
}
int Pred(){
    int f = T[root].lc;
    while (T[f].rc) f = T[f].rc;
    return f;
}
int Succ(){
    int f = T[root].rc;
    while (T[f].lc) f = T[f].lc;
    return f;
}
void Delete(int &f){
    int l = T[f].lc, r = T[f].rc;
    T[l].fa = T[r].fa = 0;
    if(!r)
    {
        if(T[T[f].fa].lc==f)
        {

            T[T[f].fa].lc=T[f].rc;
        }
        else T[T[f].fa].rc=T[f].rc;
        return ;
    }
    else
    {
        if(T[T[f].fa].lc==f)
        {

            T[T[f].fa].lc=T[f].lc;
        }
        else T[T[f].fa].rc=T[f].lc;
        return ;
    }
    int x = l;
    while (T[x].rc) x = T[x].rc; Splay(x, l);
    Update(x, r, 0);
    f = x;
}
int find(int k,int root)
{
    if(T[root].c>k) return find(k,T[root].lc);
    else if(T[root].c==k) return root;
    else return find(k,T[root].rc);
}
int findk(int r,int k)
{
    int u=lsize(r);
    if(u+1>k) return findk(T[r].lc,k);
    else if(u+1<k) return findk(T[r].rc,k-u-1);
    else return T[r].c;
}
int main(){
    int n, p, flag = 0, cnt = 0;int m;
    long long ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        //T[i].p=i;
        scanf("%d",&T[i].c);
        Insert(i);
    }
    cin>>m;
    int t;
    int le,ri,a,b,k;
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        if(t==1)
        {
            scanf("%d%d",&a,&b);
            int y=find(a,root);
            a=y;
            Delete(y);
            T[y].c=b;
            Insert(a);//
        }
        else
        {
            scanf("%d%d%d",&le,&ri,&k);
            Splay(le-1,root);
            for(int i=1;i<=n;i++) cout<<i<<" "<<T[i].c<<" "<<T[i].lc<<" "<<T[i].rc<<endl;

            cout<<endl;
            Splay(ri+1,T[root].rc);

            int res=findk(T[root].rc,k);
            printf("%d\n",res);
        }
        //for(int i=1;i<=n;i++) cout<<i<<" "<<lsize(i)<<" "<<T[i].c<<endl;//<<T[i].lc<<" "<<T[i].rc<<endl;cout<<endl;
    }
    /*
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &p, &T[i].c);
        if (p == flag || !cnt){
            Update(i, 0, 0);
            if (!cnt) root = i; else Insert(i);
            cnt++;
            flag = p;
        }else{
            Insert(i);
            int r1 = Pred(), r2 = Succ();
            Delete(root);
            if (!r1) p = r2;
            else if (!r2) p = r1;
            else if (T[i].c - T[r1].c <= T[r2].c - T[i].c) p = r1;
            else p = r2;
            ans += abs(T[p].c - T[i].c);
            ans %= MOD;
            Splay(p, root);
            Delete(root);
            cnt--;
        }
    }*/
}
