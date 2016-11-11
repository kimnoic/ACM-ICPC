#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 505
bool map[MAXN][MAXN], vis[MAXN];
int match[MAXN];
int n, k;

bool dfs( int u)
{
    int v;
    for( v = 1; v <= n; v ++)
        if( map[u][v] && !vis[v])
        {
            vis[v] = true;
            if( match[v] == -1 || dfs( match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
}

int MaxMatch()
{
    int u, ret = 0;
    memset( match, -1, sizeof match);
    for( u = 1; u <= n; u ++)
    {
        memset( vis, false, sizeof vis);
        if( dfs(u)) ret ++;
    }
    return ret;
}

int main()
{
    while( scanf( "%d%d", &n, &k) == 2)
    {
        int x, y;
        memset( map, false, sizeof map);
        for( int i = 1; i <= k; i ++)
        {
            scanf( "%d%d", &x, &y);
            map[x][y] = true;
        }
        int ans = MaxMatch();
        printf( "%d\n", ans);
    }
    return 0;
}
