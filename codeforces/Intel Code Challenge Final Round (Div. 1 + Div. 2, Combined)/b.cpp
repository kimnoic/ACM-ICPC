#include <bits/stdc++.h>
const int maxn=233;
int mp[maxn][maxn];
int n,m;
bool check(int x,int y){
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(j==x) {if(mp[i][j]!=y)cnt++;}
            else if(j==y) {if(mp[i][j]!=x) cnt++;}
            else if(mp[i][j]!=j) {cnt++;}
            if(cnt>2) return false;
        }
    }
    return true;
}
int main(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) std::cin>>mp[i][j];
    for(int i=1;i<=n;i++){
        int cnt=0;
        int flag=0;
        for(int j=1;j<=m;j++){
            if(mp[i][j]!=j) cnt++;
            if(cnt>2) {flag=1;break;}
            if(i==n && j==m){std::cout<<"YES";return 0;}
        }
        if(flag) break;
    }
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
        if(check(i,j)){
            std::cout<<"YES";return 0;
        }
    std::cout<<"NO";
    return 0;
}
