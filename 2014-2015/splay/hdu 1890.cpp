#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define PB push_back
#define MP make_pair

const int N = 200002;
const int INF = 1e9;
const int MOD = 1000000;
typedef pair<int, int> PI;
struct Tnode{
    int c, lc, rc, fa , flag , sum;
} T[N];
int a[N], b[N];

bool cmp(int i, int j){return MP(a[i], i) < MP(a[j], j);}


int root;

void Update(int f, int x, int flag){
    if (x) T[x].fa = f;
    if (f){
        if (flag) T[f].lc = x; else T[f].rc = x;
        T[f].sum=T[T[f].lc].sum+T[T[f].rc].sum+1;
    }
}
void Push(int f){
    if (!T[f].flag) return;
    int l = T[f].lc, r = T[f].rc;
    T[f].flag = 0;
    T[l].flag ^= 1, T[r].flag ^= 1;
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

void Splay(int x, int &t){
    int y, z, limit;
    y = T[x].fa; z = T[y]. fa; limit = T[t].fa;
    while (y != limit){
        if (z != limit && (T[y].lc == x) == (T[z].lc == y)) Up(y);
        Up(x); y = T[x].fa; z = T[y].fa;
    }
    t = x; Push(t);
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

int Build(int l, int r)
{
    if(l>r) return 0;
    else if(l==r)
    {
        Update(l,0,0);
        Update(l,0,1);
        T[l].flag=0;
        return l;
    }
    int mid=l+r>>1;
    Update(mid,Build(l,mid-1),1),Update(mid,Build(mid+1,r),0);
    T[mid].flag=0;
    return mid;
}

int main(){
    int n;
    while (scanf("%d", &n) == 1 && n){
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = i;
        sort(b + 1, b + n + 1, cmp);
        root = Build(1, n);
        for (int i = 1; i <= n; i++){
            Splay(b[i], root);
            printf("%d", T[T[root].lc].sum + i); if (i == n) puts(""); else printf(" ");
            if (T[root].lc) T[T[root].lc].flag ^= 1;
            Delete(root);
        }
    }
}
