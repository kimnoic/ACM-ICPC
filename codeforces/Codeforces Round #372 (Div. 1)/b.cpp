#include <bits/stdc++.h>
#define LL long long
#define Sz(x) ((int)(x).size())
#define MP std::make_pair
#define sset std::set
#define svt std::vector
#define pb push_back
#define Min std::min
#define sp std::pair
const int INF=0x3f3f3f3f;
const int maxn=1e6+10;
svt<sp <int,int> >e[maxn];
sset<sp <LL,int> >st;
svt<int>eg;
int u[maxn],v[maxn],w[maxn];
bool vis[maxn];
int dist[maxn];
int n,m,L,s,t;
void dijkstra(int start,int n){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=n;i++) dist[i]=INF;
    dist[start]=0;
    for(int i=0;i<n;i++) st.insert(MP(dist[i],i));
    for(int i=0;i<n;i++){
        int u=st.begin()->second;
        st.erase(st.begin());
        vis[u]=1;
        for(auto U:e[u]){
            int v=U.first;
            if(dist[v]>dist[u]+U.second){
                st.erase(MP(dist[v],v));
                dist[v]=dist[u]+U.second;
                st.insert(MP(dist[v],v));
            }
        }
    }
}
LL check(LL x){
    for(int i=0;i<Sz(eg);i++){
        w[eg[i]]=1+Min(x,1000000000ll);
        x-=w[eg[i]]-1;
    }
    for(int i=0;i<n;i++) e[i].clear();
    for(int i=0;i<m;i++){
        e[u[i]].pb(MP(v[i],w[i]));
        e[v[i]].pb(MP(u[i],w[i]));
    }
    dijkstra(s,n);
    return dist[t];
}

int main(){
    std::cin>>n>>m>>L>>s>>t;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",u+i,v+i,w+i);
        if(w[i]==0) eg.pb(i);
    }
    LL l=-1,r=1000000000ll*Sz(eg);
    if(check(0)>L||check(r)<L){
        printf("NO");
        return 0;
    }
    puts("YES");
    while(l+1<r){
        LL mid=(l+r)>>1;
        if(check(mid)>=L)r=mid;
        else l=mid;
    }
    check(r);
    for(int i=0;i<m;i++){
        printf("%d %d %d\n",u[i],v[i],w[i]);
    }
    return 0;
}
