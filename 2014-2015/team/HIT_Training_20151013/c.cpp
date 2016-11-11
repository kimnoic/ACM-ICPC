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
#define Max 1000010
#define INF 0x3FFFFFFFFF

int a,b,w;
struct{
    int e,next,w;
}mp[2][Max];
long long d[Max],ans;
int n,m,h[2][Max],vis[Max];
void spfa(int k){
    int v,i,b;
    queue <int>q;
    for(int i=1;i<=n;i++){
        d[i]=INF;
        vis[i]=0;
    }
    q.push(1);
    vis[1]=1;
    d[1]=0;
    while(!q.empty()){
        v=q.front();
        q.pop();vis[v]=0;
        for(int i=h[k][v];i!=-1;i=mp[k][i].next){
            b=mp[k][i].e;
            if(d[b]>d[v]+mp[k][i].w){
                d[b]=d[v]+mp[k][i].w;
                if(!vis[b]){
                    vis[b]=1;
                    q.push(b);
                }
            }
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            h[0][i]=-1;
            h[1][i]=-1;
        }
        for(int i=0;i<m;i++){
            cin>>a>>b>>w;
            mp[1][i].w=w;mp[1][i].e=a;mp[1][i].next=h[1][b];
            mp[0][i].w=w;mp[0][i].e=b;mp[0][i].next=h[0][a];
            h[0][a]=i;
            h[1][b]=i;
        }
        ans=0;
        spfa(0);
        for(int i=1;i<=n;i++)
            ans+=d[i];
        spfa(1);
        for(int i=1;i<=n;i++)
        ans+=d[i];
        cout<<ans<<endl;
    }
    return 0;
}
