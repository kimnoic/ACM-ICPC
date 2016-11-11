#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(v) int((v).size())
#define pb push_back
#define all(e) (e).begin(), (e).end()
#define LSOne(S) (S & (-S)) // bit menos significativo


#define ii pair<int,int>
#define ll long long

const int MAXN = 100005;

vector<int> adj[MAXN];

int dis[MAXN];
int pre[MAXN], pos[MAXN];
int anc[MAXN];
int sum[MAXN];

bool pai (int u, int v) {
	return pre[u]<=pre[v] && pos[v]<=pos[u];
}

int dfs (int v, int d, int &t) {
	pre[v] = t++;
	dis[v] = d;
	sum[v] = 1;
	FORR (i, sz(adj[v])) {
		int k = adj[v][i];
		if (pre[k]) continue;
		anc[k] = v;
		sum[v] += dfs (k, d+1, t);
	}
	pos[v] = t++;
	return sum[v];
}

int mem[MAXN][20];

void calc (int n) {
	memset (mem, -1, sizeof mem);
	FORR (i, n) mem[i][0] = anc[i];
	for (int j = 1; (1<<j) < n; j++) FORR (i, n) mem[i][j] = mem[mem[i][j-1]][j-1];
}

int find (int u, int k) {
	int cnt = 0;
	while (k) {
		if (k&1) u = mem[u][cnt];
		k >>= 1;
		cnt++;
	}
	return u;
}

int lca (int u, int v) {
	if (dis[u]>dis[v]) swap (u, v);
	v = find (v, dis[v]-dis[u]);
	if (u==v) return u;
	int pvt = 0;
	while (mem[u][pvt]!=mem[v][pvt]) pvt++;
	while (pvt>=0) {
		int x = mem[u][pvt], y = mem[v][pvt];
		if (x!=y) u = x, v = y;
		pvt--;
	}
	return mem[u][0];
}

int solve (int x, int y, int n) {
	if (dis[x]>dis[y]) swap (x, y);
	int l = lca (x, y);
	int s = (dis[x]+dis[y]-2*dis[l]);
	if (s&1) return 0;
	s>>=1;
	int k = find (y, s);
	int c = 0;
	int res = n;
	if (s==0) return res;
	if (dis[x]!=dis[y]) {
		res -= sum[find(y,s-1)] + (n-sum[find(y,s)]);
	} else {
		res -= sum[find(y,s-1)] + sum[find(x,s-1)];
	}
	return res;
}


int main () {
	int n;
	while (scanf (" %d", &n) != EOF) {
		FORR (i, n+1) adj[i].clear();
		FORR (i, n-1) {
			int x, y;
			scanf (" %d %d", &x, &y);
			x--, y--;
			adj[x].pb (y);
			adj[y].pb (x);
		}
		int t = 1;
		memset (pre, 0, sizeof pre);
		dfs (0, 0, t);
		calc (n);
		int m;
		scanf (" %d", &m);
		FORR (i, m) {
			int x, y;
			scanf (" %d %d", &x, &y);
			x--, y--;
			cout << solve (x, y, n) << endl;
		}
	}
}
