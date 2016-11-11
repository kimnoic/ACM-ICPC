#include <bits/stdc++.h>
using namespace std;
#define Max 200010
int a[Max];
int fa[Max];
vector<int> q[Max];
int n,m;
int cnt=0;
void dfs(int x,int step){
    int len=q[x].size();
    if(a[x]) step++;
    if(step>m) return ;
    if(!a[x]) step=0;
    if(q[x].size()==1&&x!=1)
    cnt++;
    for(int i=0;i<len;i++){
        if(q[x][i]==fa[x]) continue;
        fa[q[x][i]]=x;
        dfs(q[x][i],step);
    }
}
int main(){
    cin>>n>>m;
    fa[1]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int a,b;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    dfs(1,0);
    cout<<cnt;
    return 0;
}
