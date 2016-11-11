#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
vector<pp>bx[300*300+10];
int vis[310][310];
int ans[310][310];
int dis[310][310];
int main(){
    int n,m,p;
    cin>>n>>m>>p;
    memset(ans,63,sizeof(ans));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int t;
            cin>>t;
            bx[t].push_back(pp(i,j));
        }
    bx[0].push_back(pp(1,1));
    for(int i=0;i<=p;i++){
        int len=bx[i].size();
        for(int j=0;j<len;j++){
            int r=bx[i][j].first,c=bx[i][j].second;
            if(r==1&&c==1&&ans[r][c]==0)
                ans[r][c]=1000000000;
            for(int k=1;k<=n;k++)
                if(vis[k][c]==i)
                    ans[r][c]=min(ans[r][c],dis[k][c]+abs(k-r));
        }
        for(int j=0;j<len;j++){
            int r=bx[i][j].first,c=bx[i][j].second;
            for(int k=1;k<=m;k++)
                if(vis[r][k]!=i+1){
                    vis[r][k]=i+1;
                    dis[r][k]=ans[r][c]+abs(k-c);
                }
                else
                    dis[r][k]=min(dis[r][k],ans[r][c]+abs(k-c));
        }
    }
    cout<<ans[bx[p][0].first][bx[p][0].second];
}
