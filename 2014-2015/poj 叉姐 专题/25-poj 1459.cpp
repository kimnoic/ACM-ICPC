#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <stdlib.h>
#include <vector>
using namespace std;
#define maxn 20010
const int N = 5005;
const int M = 30005;
int np,nc;
struct Enode{
    int y, c, next;
} e[M * 2];
struct Point
{
	int son,cur,pre,lim,d;
} a[maxn];
int n, m, tot, head[N], now[N], h[N], vh[N], augc, found, flow;
int st, ed, cnt[maxn];
void Addedge(int x, int y, int c){
    e[++tot].y = y; e[tot].c = c; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].c = 0; e[tot].next = head[y]; head[y] = tot;
}
void Init(){
    int x, y, c, i;
    tot = -1; memset(head, -1, sizeof(head));
    char c1,c2,c3;
    for (i = 0; i < m; i++)
	{
		cin>>c1>>x>>c2>>y>>c3>>c;
        x+=2;
        y+=2;
        Addedge(x, y, c);
    }
    for(i=1;i<=np;i++)
	{
		cin>>c1>>x>>c2>>c;
		x+=2;
		Addedge(1,x,c);
	}
	for(i=1;i<=nc;i++)
	{
		cin>>c1>>x>>c2>>c;
		x+=2;
		Addedge(x,n,c);
	}
    memcpy(now, head, sizeof(head));
}

void Aug(int x, int st, int ed, int n){
    int p = now[x], minh = n - 1, augco = augc;
    if (x == ed){
        found = 1;
        flow += augc;
        return;
    }
    while (p != -1){
        if (e[p].c > 0 && h[e[p].y] + 1 == h[x]){
            augc = min(augc, e[p].c);
            Aug(e[p].y, st, ed, n);
            if (h[st] >= n) return;
            if (found) break;
            augc = augco;
        }
        p = e[p].next;
    }
    if (found){
        e[p].c -= augc;
        e[p ^ 1].c += augc;
    }else{
        p = head[x];
        while (p != -1){
            if (e[p].c > 0 && h[e[p].y] < minh){
                minh = h[e[p].y];
                now[x] = p;
            }
            p = e[p].next;
        }
        vh[h[x]] --;
        if (!vh[h[x]]) h[st] = n;
        h[x] = minh + 1;
        vh[h[x]] ++;
    }
}
void Maxflow(int st, int ed, int n){
    flow = 0;
    memset(h, 0, sizeof(h));
    memset(vh, 0, sizeof(vh));
    vh[0] = n;
    while (h[st] < n){
        found = 0;
        augc = 1 << 30;
        Aug(st, st, ed, n);
    }
}
int main()
{
	while(cin>>n>>np>>nc>>m)
    {
    	n+=2;
    	Init();
		Maxflow(1, n, n);
		printf("%d\n", flow);
	}
}
