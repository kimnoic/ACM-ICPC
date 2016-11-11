#pragma comment(linker,"/STACK:102400000,102400000")
#include <bits/stdc++.h>
#define mst(x,a) std::memset(x,a,sizeof(x))
#define Max std::max
//#define LL long long
typedef long long LL;
const int maxn=5e4+100;
int n,k;
struct pt{int next,v;}edge[maxn*2];
std::map<LL,int>mp;
LL ans,val[maxn],pre[maxn],p[233];
int sum,e,sz[maxn],head[maxn],vis[maxn],root,f[maxn];
void init(){mst(head,-1);mst(vis,0);e=0;ans=0;mp.clear();}
void addedge(int u,int v){edge[e].v=v;edge[e].next=head[u];head[u]=e++;}
void getrt(int u,int fa){
    f[u]=0,sz[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v] && v!=fa){
            getrt(v,u);
            sz[u]+=sz[v];
            f[u]=std::max(f[u],sz[v]);
        }
    }
    f[u]=std::max(f[u],sum-f[u]);
    if(f[u]<f[root]) root=u;
}
LL cal(LL x){
    LL ret=0,bas=1;
    for(int i=1;i<=k;i++){
        LL cnt=0;
        while(x%p[i]==0){
            x/=p[i];cnt++;
        }cnt%=3;
        ret+=cnt*bas;
        bas*=3;
    }
    return ret;
}
LL ccal(LL x){
    LL ret=0,bas=1;
    for(int i=1;i<=k;i++){
        ret+=((3-(x%3))%3)*bas;
        bas*=3;
        x/=3;
    }
    return ret;
}
LL uni(LL x,LL y){
    LL ret=0,bas=1;
    for(int i=1;i<=k;i++){
        ret+=(((x%3)+(y%3))%3)*bas;
        x/=3,y/=3;
        bas*=3;
    }
    return ret;
}
void dfsdis(int u,int fa,LL va,std::map<LL,int> &mapp){
    if(mapp.count(va)) mapp[va]++;
    else mapp[va]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]&&v!=fa){
            dfsdis(v,u,uni(va,pre[v]),mapp);
        }
    }
}
void solve(int u){
    vis[u]=1;
    LL temp=cal(val[u]);mp.clear();
    mp[temp]=1;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]){
            LL tm=pre[v];std::map<LL,int>tmp;
            tmp.clear();
            dfsdis(v,u,tm,tmp);
            for(auto it:tmp){
                LL ptemp=ccal(it.first);
                if(mp.count(ptemp)) ans+=mp[ptemp]*it.second;
            }
            for(auto it:tmp){
                LL ptemp=uni(it.first,pre[u]);
                if(mp.count(ptemp)) mp[ptemp]+=it.second;
                else mp[ptemp]=it.second;
            }
        }
    }
    mp.clear();
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]){
            sum=sz[v],root=0;
            getrt(v,0);
            solve(root);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)){
        init();
        scanf("%d",&k);for(int i=1;i<=k;i++) scanf("%I64d",p+i);
        for(int i=1;i<=n;i++) scanf("%I64d",&val[i]);int u,v;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);addedge(u,v);addedge(v,u);
        }
        for(int i=1;i<=n;i++) {
                pre[i]=cal(val[i]);
                if(!pre[i]) ans++;
        }
        sum=n,root=0,f[0]=n+1;
        getrt(1,0);
        solve(root);
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
6
3 2 3 5
6 1 30 150 150 12
1 2
2 4
1 3
3 5
3 6

*/
