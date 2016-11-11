#include <bits/stdc++.h>
const int maxn=110;
int mp[maxn][maxn];
int v[maxn][maxn];
int x,y;
int n,m,T,l,r;
int main(){
    std::cin>>T;
    while(T--){
        std::cin>>n>>m;
        memset(mp,0,sizeof(mp));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            std::cin>>l>>r;
            for(int j=l;j<=r;j++){
                mp[i][j]=1;
                for(int k=1;k<=m;k++) v[i][k]++;
                for(int k=1;k<=n;k++) v[k][j]++;
            }
//            for(int i=1;i<=n;i++){
//            for(int j=1;j<=m;j++){
//                std::cout<<v[i][j]<<" ";
//            }
//            std::cout<<std::endl;
//            }
//            std::cout<<std::endl;
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=m;j++){
//                std::cout<<mp[i][j]<<" ";
//            }
//            std::cout<<std::endl;
//        }
        int sum=0;
        while(1){
            int maxx=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(v[i][j]>maxx&&mp[i][j]){
                        maxx=v[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
//            std::cout<<"pos "<<x<<" "<<y<<std::endl;
            if(!maxx) break;
            sum++;
            for(int i=1;i<=m;i++){
                if(mp[x][i]){
                    for(int j=1;j<=m;j++){
                        v[x][j]--;
                    }
                    mp[x][i]=0;
                }
            }
            for(int i=1;i<=n;i++){
                if(mp[i][y]){
                    for(int j=1;j<=n;j++){
                        v[j][y]--;
                    }
                    mp[i][y]=0;
                }
            }
//            std::cout<<std::endl;
//            for(int i=1;i<=n;i++){
//                for(int j=1;j<=m;j++){
//                    std::cout<<v[i][j]<<" ";
//                }
//                std::cout<<std::endl;
//            }
        }
        std::cout<<sum<<std::endl;
    }
    return 0;
}
/*
3
2 4
1 3
2 4

*/
