#pragma comment(linker,"/STACK:102400000,102400000")
#include <bits/stdc++.h>
#define mst(x,a) std::memset(x,a,sizeof(x))
#define Max std::max
#define LL long long
const int maxn=1e5+100;
const int maxm=1e6+100;
const int inf=1e9;
const int mod=1e6+3;
struct pt{int next,v;} edge[2*maxn];
int n,k,e,mi,cnt,sum;
LL dis[maxn],tmp[maxn],val[maxn],ine[maxm],mp[maxm];
int sz[maxn],head[maxn],vis[maxn],id[maxn],num,root,ans1,ans2,f[maxn];
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
void pre(){
	ine[1]=1;
	for(int i=2;i<mod;i++){
		int a=mod/i,b=mod%i;
		ine[i]=(ine[b]*(-a)%mod+mod)%mod;
	}
}
void init(){
	mst(head,-1);
	mst(vis,0);
	e=cnt=0;
	ans1=inf,ans2=inf;
}
void add(int u,int v){
	edge[e].v=v;edge[e].next=head[u];head[u]=e++;
}
void getrooot(int x,int fa){
	f[x]=0;sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v] && v!=fa){
			getrooot(v,x);
			sz[x]+=sz[v];
			f[x]=std::max(f[x],sz[v]);
		}
	}
	f[x]=std::max(f[x],sum-sz[x]);
	if(f[x]<f[root]) root=x;
}
void dfsdis(int u,int fa){
	tmp[++num]=dis[u];id[num]=u;
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;

		if(!vis[v] && v!=fa){
			dis[v]=(dis[u]*val[v])%mod;
			dfsdis(v,u);
		}
	}
}
void query(int x,int id){
	x=ine[x]*k%mod;
	if(!mp[x]) return ;
	int xx=mp[x];
	if(xx>id) std::swap(xx,id);
	if(ans1>xx || (ans1==xx && ans2>id))
	ans1=xx,ans2=id;
}
void solve(int u){
    vis[u]=1;
    mp[val[u]]=u;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]){
            num=0;dis[v]=val[v];dfsdis(v,u);
            for(int j=1;j<=num;j++) query(tmp[j],id[j]);
            num=0;dis[v]=(val[v]*val[u])%mod;dfsdis(v,u);
            for(int j=1;j<=num;j++) {
                int xx=mp[tmp[j]];
                if(!xx || id[j]<xx ) mp[tmp[j]]=id[j];
            }
        }
    }
    mp[val[u]]=0;
    for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v]){
			num=0;dis[v]=(val[v]*val[u])%mod; dfsdis(v,u);
			for(int j=1;j<=num;j++) mp[tmp[j]]=0;
		}
    }
    for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v]){
			sum=sz[v];root=0;
			getrooot(v,0);
            solve(root);
		}
    }
}
int main(){
	pre();
    while(~scanf("%d%d",&n,&k)){
        init();
        for(int i=1;i<=n;i++) val[i]=read( );
        for(int i=1;i<n;i++){
            int u,v;u=read(),v=read( );
            add(u,v);add(v,u);
        }
        sum=n;root=0,f[0]=n+1;
        getrooot(1,0);
        solve(root);
        if(ans1==inf) printf("No solution\n");
        else printf("%d %d\n",ans1,ans2);
    }
	return 0;
}
