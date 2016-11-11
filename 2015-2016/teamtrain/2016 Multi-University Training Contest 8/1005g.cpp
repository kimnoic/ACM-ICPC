#include <bits/stdc++.h>
std::map<long long,int>mp,mpp;
int T,n,m,k;
long long ans,temp;
const int maxn=3e5+10;
const int mod=3e5;
long long a[maxn];
bool check(long long x){
    long long t=x;
    while(t/10){
        if((t%10)<(t/10)%10) return false;
        t/=10;
    }
    return true;
}
int num[12];
std::map<long long,bool>vis;
int dfs(int x[],int top){
    long long xx=0;
    bool flag=1;
    for(int i=1;i<=top;i++){
        xx*=10;
        xx+=x[i];
        if(x[i-1]>x[i]) flag=0;
    }
//    std::cout<<xx<<" "<<mpp[xx]<<std::endl;
    if(vis[xx]) return mpp[xx];
    if(flag&&mp[xx]) {vis[xx]=1;return mpp[xx]=mp[xx];}
    if(flag) {vis[xx]=1; return mpp[xx]=0;}

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[i]>x[j]){
                std::swap(x[i],x[j]);
                mpp[xx]+=dfs(x,n);
                std::swap(x[i],x[j]);
            }
        }
    }
    vis[xx]=1;
    return mpp[xx];
}
int sol(){
    int vv[100000000];
    int v[100000000];
    for(int i=1;i<=m;i++){
        ans=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&k);
            ans*=10;
            ans+=k;
        }
//            std::cout<<ans<<std::endl;
        a[i]=ans;
        v[ans]++;
    }
}
int main(){
    std::cin>>T;
    while(T--){
        std::cin>>n>>m;
        mp.clear();
        mpp.clear();
        vis.clear();
        for(int i=1;i<=m;i++){
            ans=0;
            for(int j=1;j<=n;j++){
                scanf("%d",&k);
                ans*=10;
                ans+=k;
            }
//            std::cout<<ans<<std::endl;
            a[i]=ans;
            if(!mp[ans]){
                mp[ans]=1;
            }
            else mp[ans]++;
        }
        if(n>5){
            std::cout<<sol()<<std::endl;
            continue;
        }
        ans=0;
        for(int i=1;i<=m;i++){
            int top=n;
            long long tem=a[i];
            while(tem){
                num[top--]=tem%10;
                tem/=10;
            }
//            for(int i=1;i<=n;i++) std::cout<<num[i]<<" ";
//            std::cout<<std::endl;
            ans+=dfs(num,n);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
