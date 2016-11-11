#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 10
char mp[Max][Max];
int n,m,k;
int cnt;
int vis[Max];
void dfs(int step,int u){
    if(u==k){
        cnt++;return ;
    }
    if(step>n) return ;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&mp[step][i]=='#'){
            vis[i]=1;
            dfs(step+1,u+1);
            vis[i]=0;
        }
    }
    dfs(step+1,u);
    return ;
}
int main(){
    while(scanf("%d%d",&n,&k)){
        cnt=0;
        if(k==-1&&n==-1) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf(" %c",&mp[i][j]);
            }
        }
        dfs(1,0);
        cout<<cnt<<endl;
    }
    return 0;
}
