#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int fa[maxn];
double v[maxn];
int num[maxn];
vector<int>mp[maxn];
int dfs(int u){
    int sum=0;
    if(mp[u].size()==0){
        num[u]=1;
        return num[u];
    }
    for(int i=0;i<mp[u].size();i++){
        sum+=dfs(mp[u][i]);
    }
    num[u]=sum+1;
    return num[u];
}
void dfs2(int u){
    double sum=num[u];
    int len=mp[u].size();
    for(int i=0;i<mp[u].size();i++){
        int k=mp[u][i];
        v[k]=v[fa[k]]+1;
        v[k]+=0.5*(sum-1-num[k]);
        dfs2(k);
    }
}
int main(){
    int n;
    fa[1]=1;
    num[1]=1;
    cin>>n;
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        fa[i]=t;
        mp[t].push_back(i);
    }
    num[1]=1;
    dfs(1);
    v[1]=1;
    dfs2(1);
    for(int i=1;i<=n;i++) cout<<v[i]<<" ";
    return 0;
}
