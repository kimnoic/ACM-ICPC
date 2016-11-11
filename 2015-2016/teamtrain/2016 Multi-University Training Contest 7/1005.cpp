#include <bits/stdc++.h>
const int maxn=1e3+10;
int a[maxn],n,T;
int b[maxn],cnt;
int mp[maxn][maxn];
struct pt{
    int u,v;
}p[maxn*maxn];

struct pr{
    int v,id;
}pp[maxn];

bool cmp(pr a,pr b){
    return a.v>b.v;
}
std::vector<int> fa[maxn];
bool vis[maxn];
void dfs(int a){
    for(int i=0;i<fa[a].size();i++){
        pp[fa[a][i]].v--;
        if(fa[fa[a][i]].size()){
            dfs(fa[a][i]);
        }
    }
}
void solve(){
    cnt=0;
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));
    int mxx=pp[1].v;
    int idd=1;
    vis[1]=1;
    for(int i=1;i<=n;i++) b[i]=pp[i].v;
    for(int i=2;i<=n;i++){
        if(pp[i].v<mxx){
            mp[idd][i]=1;
            vis[i]=1;
            fa[pp[i].id].push_back(idd);
            p[++cnt].u=idd;
            pp[idd].v-=(pp[i].v+1);
            p[cnt].v=pp[i].id;
            mxx=0;
            for(int j=1;j<=i;j++){
                if(vis[j]){
                    if(pp[j].v>=mxx){
                        mxx=pp[j].v;
                        idd=j;
                    }
                }
            }
        }
//        for(int i=1;i<=n;i++) std::cout<<pp[i].v<<std::endl;
//        std::cout<<std::endl;
    }

    for(int i=n;i>=1;i--){
        if(!vis[i]){
            int j;
            for(j=i-1;j>=1;j--){
                if(vis[j]&&b[j]==b[i]) break;
            }
            if(vis[j]&&b[i]==b[j]){
                for(int k=1;k<=n;k++){
                    if(mp[pp[j].id][k]){
                        p[++cnt].u=pp[i].id;
                        p[++cnt].v=k;
                        pp[i].v-=(b[k]+1);
                    }
                }
                //std::cout<<j<<std::endl;
                if(pp[i].v!=0){
                    //std::cout<<i<<std::endl;
                    for(int k=0;k<fa[j].size();k++){
                        if(pp[fa[j][k]].v!=0) {
                            pp[fa[j][k]].v--;
                            p[++cnt].u=pp[fa[j][k]].id;
                            p[cnt].v=pp[i].id;
                            //std::cout<<"asfasdf    "<<fa[j][k]<<std::endl;
                            dfs(fa[j][k]);
                            break;
                        }
                    }
                }
                vis[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        std::cout<<pp[i].v<<std::endl;
    }
    for(int i=1;i<=n;i++){
        if(pp[i].v!=0){
            printf("No\n");
            return ;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=cnt;i++){
        printf("%d %d\n",p[i].u,p[i].v);
    }
}
int main(){
    std::cin>>T;
    while(T--){
        std::cin>>n;
        for(int i=1;i<=n;i++){
            std::cin>>pp[i].v;
            pp[i].id=i;
        }
        std::sort(pp+1,pp+n+1,cmp);
        //for(int i=1;i<=n;i++) std::cout<<pp[i].v<<std::endl;
        solve();
    }
    return 0;
}
