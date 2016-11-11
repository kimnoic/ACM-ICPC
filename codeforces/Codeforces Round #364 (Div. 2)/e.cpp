#include<bits/stdc++.h>
using namespace std;
const int maxn = 200100;
#define LL long long
struct pt{
	int x,y,next;
}p[maxn*3];
int cnt;
int edge[maxn],n,x,sz[maxn],dp[maxn],k;
int y,q;
int vis[maxn];
void dfs(int u){
	sz[u]=vis[u];
	for(int e=edge[u];e!=-1;e=p[e].next){
		int v=p[e].y;
		if(dp[v]){
            k++;
		}
		if(dp[v]==0){
			dp[v]=dp[u]+1;
			dfs(v);
			sz[u]+=sz[v];
		}
	}
}
int main(){
	cnt=0;dp[1]=1;
	cin>>n>>q;
	q*=2;
	for(int i=1;i<=q;i++){
		cin>>x;
		vis[x]=1;
		k++;
	}
	memset(edge,-1,sizeof(edge));
	for(int i=1;i<n;i++){
		cin>>x>>y;
		p[++cnt].x=x;
		p[cnt].y=y;
        p[cnt].next=edge[x];
        edge[x]=cnt;
        k++;
        swap(x,y);
        p[++cnt].x=x;
        p[cnt].y=y;
        p[cnt].next=edge[x];
        edge[x]=cnt;
	}

	dfs(1);
	LL ans=0;
	for(int i=1;i<=cnt;i+=2){
		x=p[i].x,y=p[i].y;
		if(dp[x]<=dp[y]);else swap(x,y);
		LL l=q-sz[y],r=sz[y];
		ans+=min(l,r);
	}
	if(k) printf("%I64d",ans);
	return 0;
}
