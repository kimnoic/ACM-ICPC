#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define N 205
int uN,vN;
int g[N][N];
int match[N];
bool used[N];
bool dfs(int u){
    for(int i=0;i<=vN;i++)
      if(g[u][i]&&!used[i]){
          used[i]=true;
          if(match[i]==-1||dfs(match[i])){
              match[i]=u;
              return true;
          }
      }
    return false;
}
int hungary(){
    int sum=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=uN;i++){
        memset(used,0,sizeof(used));
        if(dfs(i)) sum++;
    }
    return sum;
}
int main(){
     int t;
     while(scanf("%d%d",&uN,&vN)!=EOF){
         memset(g,0,sizeof(g));
         for(int i=1;i<=uN;i++){
             int k;
             scanf("%d",&k);
             while(k--){
                 scanf("%d",&t);
                 g[i][t]=1;
             }
         }
         printf("%d\n",hungary());
     }
     return 0;
}
