#include <bits/stdc++.h>
const int maxn = 2e5+10;
const int mod = 1e9+7;
#define LL long long
LL nxt[maxn],d[maxn],temp,ans;
int vis[maxn];
int n;
LL sov(int k){
    LL ret=1;
    LL a=2;
    while(k){
        if(k&1) ret=a*ret%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ret;
}
void dfs(int i,int a,int flag){
    vis[i]=flag;
    d[i]=a;
    if(!vis[nxt[i]]) dfs(nxt[i],a+1,flag);
    else if(vis[nxt[i]]==vis[i]){
        //std::cout<<pre<<" "<<d[pre]-d[i]<<std::endl;
        //std::cout<<sov(d[i]-d[nxt[i]]+1)-2<<std::endl;
        ans*=((sov(d[i]-d[nxt[i]]+1)-2)%mod);
//        std::cout<<ans<<std::endl;
        ans%=mod;
        temp+=(d[i]-d[nxt[i]]+1);
        return ;
    }
}
int main(){
    std::cin>>n;
    memset(vis,0,sizeof(vis));
    ans=1;temp=0;
    for(int i=1;i<=n;i++) std::cin>>nxt[i];
    for(int i=1;i<=n;i++){
        //std::cout<<i<<std::endl;
        if(!vis[i]) dfs(i,1,i);
    }
    //std::cout<<ans<<std::endl;
    ans*=sov(n-temp);
    ans%=mod;
    std::cout<<ans;
    return 0;
}
