#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int SIZE = 22;
int rch[1<<SIZE], sum[1<<SIZE], q[1<<SIZE], u[405], v[405];
bool show[1<<SIZE];
inline int lb(int x) {return x&(-x);}

int main() {
    int T;
    scanf("%d",&T);
    for(int cs = 1; cs <= T; cs++) {
        int n, m;
        scanf("%d%d",&n,&m);
        fill(rch , rch + (1<<n) , 0);
        fill(show , show + (1<<n) , 0);
        fill(sum , sum + (1<<n) , 0);
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            ::u[i] = u;
            ::v[i] = v;
            rch[1<<u] |= 1<<v;
            rch[1<<v] |= 1<<u;
        }

        for(int i = 1; i < 1<<n; i++) {
            rch[i] |= rch[i-lb(i)] | rch[lb(i)]; //处理出当前点集临接的点
        }for(int i=0;i<1<<n;i++){
            cout<<i<<" "<<rch[i]<<endl;
        }
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) show[q[r++] = 1<<i] = true;
        //标程上学来的神奇bfs
        while(l < r) {
            int c = q[l++]; //当前选的点集
            int left = rch[c] ^ (rch[c] & c); //剩下可达的没去的点集
            while(left) {
                int now = lb(left) | c;
                if(!show[now]) show[q[r++] = now] = true;
                left -= lb(left);
            }
        }
        int all = 0;
        for(int i = 0; i < 1 << n; i++) {
            int j = (1 << n) - 1;
            j ^= i;
            if(show[i] && show[j]) {
                sum[i]++;
                all++;
                sum[j]++;
            }
        }
        //all >>= 1;
        for(int j = 0; j < n; j++) {
            for(int i =(1<<n)-1;i>=0;--i) if(!(i>>j&1)) sum[i] += sum[i^(1<<j)];
            //高维前缀和，sum[i]代表点i超集数目，即包含i的连通的点集数目
        }
        printf("Case #%d: ",cs);
        for(int i = 0; i < m; i++) {
            printf("%d%c",(all - sum[(1<<u[i]) | (1<<v[i])])/2, " \n"[i+1==m]);
            //all是所有连通点集数目，减去同时包含u和v的连通点集个数，剩下就是以(u,v)为割的点集数目的两倍
        }
    }

}
