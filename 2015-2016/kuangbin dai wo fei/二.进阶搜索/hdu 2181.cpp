#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 30
bool vis[Max];
int pre[Max];
int n,m;
int ans=0;
void print(int a){
    if(a!=m){
        print(pre[a]);
        cout<<" "<<a;
    }
}
vector<int>q[Max];
void dfs(int a,int cnt){
    if(cnt<20&&vis[m]) return ;
    if(cnt==20&&a==m){
        cout<<++ans<<":  "<<m;
        print(pre[m]);
        cout<<" "<<m<<endl;
    }
    for(int i=0;i<=2;i++){
        int temp=q[a][i];
        if(!vis[temp]){
            vis[temp]=1;
            pre[temp]=a;
            dfs(temp,cnt+1);
            vis[temp]=0;
        }
    }
}
int main(){
    int a,b,c;
    for(int i=1;i<=20;i++){
        q[i].clear();
        cin>>a>>b>>c;
        q[i].push_back(a);
        q[i].push_back(b);
        q[i].push_back(c);
    }
    while(1){
        cin>>m;
        if(m==0) break;
        memset(vis,0,sizeof(vis));
        memset(pre,0,sizeof(pre));
        dfs(m,0);
    }
    return 0;
}
