#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
#define maxn 20010
#define Max 60010
const int N = 5005;
const int M = 60005;
struct Enode{
    int y, c, next;
} e[M * 2];
struct edge
{
	int u,v;
	edge () {}
	edge(int _u,int _v):u(_u),v(_v) {}
};
vector <edge> g[Max];
int dis[Max]={};
bool inq[Max];
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
    for (i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &c);
        Addedge(x, y, c);
        g[x].push_back(edge(y,c));
    }
    memcpy(now, head, sizeof(head));
}

void Aug(int x, int st, int ed, int n){
    int p = now[x], minh = n - 1, augco = augc;
    if (x == ed){
        found = 1;
        flow += 1;
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
int path[Max];
void spfa(int s,int t)
{
	memset(inq,false,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	memset(path,0,sizeof(path));
	dis[s]=0;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		inq[now]=false;
		int u,v;
		for(int i=0;i<g[now].size();i++)
		{
			u=g[now][i].v;
			v=g[now][i].u;
			if(dis[v]>u+dis[now])
			{
				dis[v]=u+dis[now];
				path[v]=now;
				if(!inq[v])
				{
					inq[v]=true;
					Q.push(v);
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d%d", &n, &m))
    {
    	Init();
		Maxflow(1, n, n);
		printf("%d ", flow);
		int cnt=1;
		int y=n;
		spfa(1,n);
		while(path[y]!=1)
		{
			cnt++;
			y=path[y];
		}
		cout<<m-cnt<<endl;
	}
}
