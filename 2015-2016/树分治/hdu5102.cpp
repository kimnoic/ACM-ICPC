#include <bits/stdc++.h>
#define sq std::queue
#define pii std::pair<int,int>
#define MP std::make_pair
#define sp std::pair
#define fi first
#define se second
#define mst(x,a) std::memset(x,a,sizeof(x))
const int maxn=1e5+100;
sq<sp<pii,int> >q;
int T,n,k,head[maxn],ans,e;
struct pt{int v,next;}edge[maxn*2];
void init(){mst(head,-1),e=0;while(!q.empty())q.pop();ans=0;}
void addedge(int u,int v){
    edge[e].v=v;edge[e].next=head[u];head[u]=e++;
}
void solve(){
    int cnt=0;
    while(!q.empty()){
        sp<pii,int> temp=q.front();q.pop();
        int u=temp.fi.fi,v=temp.fi.se,d=temp.se;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int vv=edge[i].v;
            if(vv!=v){
                cnt++;
                ans+=d+1;
                q.push(MP(MP(vv,u),d+1));
            }
            if(cnt>=k) break;
        }
        if(cnt>=k) break;
    }

}
int main(){
    std::cin>>T;
    while(T--){
        std::cin>>n>>k;
        init();
        for(int i=1;i<=n;i++) q.push(MP(MP(i,i),0));
        for(int i=1;i<n;i++){
            int u,v;
            std::cin>>u>>v;
            addedge(u,v);
            addedge(v,u);
        }
        k*=2;
        solve();

        std::cout<<ans/2<<std::endl;
    }
    return 0;
}
