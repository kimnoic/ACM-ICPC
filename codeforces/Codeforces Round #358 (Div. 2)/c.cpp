#include<bits/stdc++.h>
using namespace std;

const int maxn = 100100;
struct pt{
	int x,y,wei;
	int nxt;
}s[maxn*2];
int fst[maxn+12],son[maxn+12];
long long dep[maxn+3],mdp[maxn+5],ss[maxn+44],ans,f[maxn];

void dfs(int u,int fa){
	f[u]=fa;
	for(int e=fst[u];e!=-1;e=s[e].nxt){
		int v=s[e].y;
		if(v!=fa){
			dep[v]=dep[u]+(long long)s[e].wei;
			mdp[v]=max(mdp[u]+(long long)s[e].wei,(long long)s[e].wei);
			mdp[v]=max(mdp[v],(long long)0);
			dfs(v,u);
		}
	}
}
int vis[maxn];
int cnt,x,y,w;
int ck=0;
void del(int u){
	vis[u]=1;
	ck++;
	for(int e=fst[u];e!=-1;e=s[e].nxt){
		int v=s[e].y;
		if(v!=f[u] && !vis[v]){
			del(v);
		}
	}ans++;
}

void add(int x,int y,int w){
	cnt++;
	s[cnt].nxt=fst[x];fst[x]=cnt;
	s[cnt].x=x;
	s[cnt].y=y;
	s[cnt].wei=w;
	ck++;
}
int n;
int main(){
    ans=0;
	cin>>n;
	ck=0;
	for(int i=0;i<maxn;i++) fst[i]=-1;
	for(int i=1;i<=n;i++)
        cin>>ss[i];
	for(int i=1;i<n;i++){
        int tempa,tempb;
		cin>>tempa>>tempb;
		add(tempa,i+1,tempb);
		add(i+1,tempa,tempb);
		ck++;
	}
	dfs(1,1);
	for(int i=1;i<=n;i++)
        if(!(!vis[i]&&ss[i]<mdp[i])){
            continue;
        }
		else {
			del(i);
		}
    if(ck)
	cout<<ans<<endl;
	return 0;
}
