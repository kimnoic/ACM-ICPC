#include <bits/stdc++.h>
using namespace std;
vector<int>a[100100];
int vis[100100];
int n,m;
int main(){
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    int mi,ma;
    for(int i=1;i<=m;i++){
        cin>>mi>>ma;
        a[min(mi,ma)].push_back(max(mi,ma));
    }
    for(int i=1;i<=n;i++){
        int k=vis[i];
        int y;
        if(k==2){
            y=1;
        }
        else {
            if(a[i].size()) vis[i]=1;
            y=2;
        }
        for(int j=0;j<a[i].size();j++){
            if(vis[a[i][j]]==0){
                vis[a[i][j]]=y;
            }
            else if(vis[a[i][j]]!=y){
                cout<<0;
                return 0;
            }
        }
    }
    int minn=0,maxx=n;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            minn=max(i,minn);
        }
        else if(vis[i]==2){
            maxx=min(i,maxx);
        }
    }
    if(maxx<=minn) cout<<0;
    else {
        if(m==0) cout<<n-1;
        else {
            cout<<maxx-minn;
        }
    }
    return 0;
}
