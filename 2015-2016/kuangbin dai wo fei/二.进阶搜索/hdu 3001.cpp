#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define Max 60000
#define N 12
#define REP(i,a,n) for(int i=a;i<=n;i++)
int state[N],vis[Max][N],dp[Max][N],mp[N][N],n,m;

void init(){
    state[0]=1;
    REP(i,1,10){
        state[i]=state[i-1]*3;
    }
    REP(i,0,state[10]){
        int temp=i;
        REP(j,0,10){
            vis[i][j]=temp%3;
            temp/=3;
        }
    }
}
int main(){
    init();
    int u,v,w,ans;
    while(cin>>n>>m){
        memset(dp,INF,sizeof(dp));
        memset(mp,INF,sizeof(mp));
        REP(i,0,n-1) dp[state[i]][i]=0;
        while(m--){
            cin>>u>>v>>w;
            u--,v--;
            mp[u][v]=mp[v][u]=min(mp[u][v],w);
        }
        ans=INF;
        REP(i,0,state[n]-1){
            bool flag=true;
            REP(j,0,n-1){
                if(!vis[i][j]) flag=false;
                if(dp[i][j]==INF) continue;
                REP(k,0,n-1)
                    if(j!=k){
                        if(vis[i][k]>=2) continue;
                        if(mp[j][k]==INF) continue;
                        dp[i+state[k]][k]=min(dp[i+state[k]][k],dp[i][j]+mp[j][k]);
                }
            }
            if(flag){
                REP(j,0,n-1){
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}

