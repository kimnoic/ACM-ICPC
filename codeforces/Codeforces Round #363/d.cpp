#include<bits/stdc++.h>
using namespace std;
const int maxn=200101;
int fa[maxn],rt,vis[maxn],ans,k;
void dfs(int u,int t){
	vis[u]=t;
	if(fa[u]==u){
		if(fa[u]!=rt){
			fa[u]=rt;
			k++;
			ans++;
		}
		return;
	}
	if(!vis[fa[u]])
		dfs(fa[u],t);
	else{
		if(vis[fa[u]]==vis[u]){
			if(rt==0)
				fa[u]=rt=u;
			else
				fa[u]=rt;
			ans++;
			k++;
		}
	}
}
int n;

int main(){
	cin>>n;
	k=1;
	for(int i=1;i<=n;i++){
		cin>>fa[i];
		k++;
		if(fa[i]==i)
			rt=i;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i,i);
		}
    if(k)
        cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<fa[i]<<" ";
	return 0;
}
