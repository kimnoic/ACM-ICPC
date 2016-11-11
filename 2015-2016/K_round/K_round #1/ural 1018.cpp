#include <bits/stdc++.h>
using namespace std;
int n,q;
#define Max 2333
vector<int>f[Max];
int val[Max][Max];
int dp[Max][Max],vis[Max];
struct{
    int lc,rc,val;
}p[Max];
int a,b,c;
void init(){
    memset(val,-1,sizeof(val));
    memset(p,0,sizeof(p));
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        val[a][b]=val[b][a]=c;
    }
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
}
void build(int a){
    vis[a]=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&val[a][i]!=-1){
            if(!p[a].lc){
                p[a].lc=i;
            }
            else p[a].rc=i;
            p[i].val=val[a][i];
            build(i);
        }
    }
}
int dfs(int rt,int m){
    if(rt==0||m<=0) return dp[rt][m]=0;
    if(dp[rt][m]!=-1) return dp[rt][m];
    dp[rt][m]=0;
    for(int x=0;x<m;x++){
        int y=m-1-x;
        int sl,st,lch,rch;
        lch=p[rt].lc;
        rch=p[rt].rc;
        sl=dfs(lch,x);
        st=dfs(rch,y);
//        cout<<dp[rt][m]<<endl;
        dp[rt][m]=max(dp[rt][m],sl+st);
//        cout<<rt<<" "<<dp[rt][m]<<" "<<p[rt].val<<endl;
    }
    //cout<<dp[rt][m]<<endl;
    return dp[rt][m]+=p[rt].val;
    //cout<<dp[rt][m]<<" "<<p[rt].val<<endl;

}
int main(){
    init();
    build(1);
//    for(int i=1;i<=n;i++){
//        cout<<i<<"lc is "<<p[i].lc<<" rc is "<<p[i].rc<<" val is "<<p[i].val<<endl;
//    }
    dfs(1,q+1);
    cout<<dp[1][q+1];
    return 0;
}
