#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200002;
const int INF = 1e9;
const int MOD = 1000000;

struct Tnode{
    int c, lc, rc, fa;
} T[N];

int root;

void Update(int f, int x, int flag){
    if (x) T[x].fa = f;
    if (f){
        if (flag) T[f].lc = x; else T[f].rc = x;
    }
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
int MINMAX()
{
    int f=T[root].lc;
    while(T[root].rc) f=T[f].rc;
    return f;
}
int MAXMIN()
{
    int f=T[root].rc;
    while(T[root].lc) f=T[f].rc;
}
void Delete(int &f){
    int l = T[f].lc, r = T[f].rc;
    T[l].fa = T[r].fa = 0;
    if (!l || !r){f = l + r; return;}
    int x = l;
    while (T[x].rc) x = T[x].rc; Splay(x, l);
    Update(x, r, 0);
    f = x;
}
int aa=0,bb=0;
int main(){
    long long res=0;
    int n;
    cin>>n;int cnt_a=0;int cnt_b=0;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if(a==0)
        {
            if(cnt_b==0)
            {
                cnt_a++;T[n].c=b;
                Insert(n);
            }
            else if(cnt_b!=1)
            {
                T[n].c=b;
                Insert(n);
                int minf=MINMAX();
                int maxf=MAXMIN();
                int re;
                int s1=b-T[minf].c;
                int s2=T[maxf].c-b;
                int r;
                if(s1>=s2) {re=minf;r=s1;}
                else {re=maxf;r=s2;}
                Delete(re);
                Delete(n);
                res+=r;
                cnt_b--;
            }
            else
            {
                res+=abs(b-T[root].c);
                Delete(root);
                cnt_b=0;
            }
        }
        else
        {
            if(cnt_a==0)
            {
                cnt_b++;
                T[n].c=b;
                Insert(n);
            }
            else if(cnt_a!=1)
            {
                T[n].c=b;
                Insert(n);
                int minf=MINMAX();
                int maxf=MAXMIN();
                int re;
                int s1=b-T[minf].c;
                int s2=T[maxf].c-b;
                int r;
                if(s1>=s2) {re=minf;r=s1;}
                else {re=maxf;r=s2;}
                Delete(re);
                Delete(n);
                res+=r;
                cnt_a--;
            }
            else
            {
                res+=abs(b-T[root].c);
                Delete(root);
                cnt_a=0;
            }
        }

    }cout<<res<<endl;
    return 0;
}
