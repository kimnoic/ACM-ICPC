#include <bits/stdc++.h>
const int maxn=22;
int rch[1<<maxn],sum[1<<maxn],q[1<<maxn],u[maxn*maxn],v[maxn*maxn];
bool vis[1<<maxn];
int lowbit(int a){
    return a&(-a);
}
int n,m,T;
void init(){
    memset(rch,0,sizeof(rch));
    memset(sum,0,sizeof(sum));
    memset(q,0,sizeof(q));
    memset(u,0,sizeof(u));
    memset(v,0,sizeof(v));
    memset(vis,0,sizeof(vis));
    std::cin>>n>>m;
    int uu,vv;
    for(int i=0;i<m;i++){
        scanf("%d%d",&uu,&vv);
        u[i]=uu;
        v[i]=vv;
        rch[1<<uu] |= 1<<vv;
        rch[1<<vv] |= 1<<uu;
//      std::cout<<(1<<uu)<<" "<<rch[1<<uu]<<std::endl;
//      std::cout<<(1<<vv)<<" "<<rch[1<<vv]<<std::endl<<std::endl;
    }
}
void solve(){
    for(int i=0;i<(1<<n);i++){
        rch[i] |= rch[i-lowbit(i)] | rch[lowbit(i)];
    }
    int l=0,r=0;
    for(int i=0;i<n;i++){
        vis[q[r++]=(1<<i)]=true;
    }
    while(l<r){
        int val=q[l++];
        int temp=rch[val]^(rch[val]&val);
        for(int i=temp;i>0;i-=lowbit(i)){
            int now=lowbit(i)|val;
            if(!vis[now]) vis[q[r++]=now]=true;
        }
    }
}

int main(){
    int _case=0;
    std::cin>>T;
    while(T--){
        init();
        solve();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int k=(1<<n)-1;
            k=k^i;
            if(vis[i]&&vis[k]){
                //std::cout<<"asdf"<<std::endl;
                sum[i]++;
                sum[k]++;
                ans++;
            }
        }
        for(int j=0;j<n;j++){
            for(int i=(1<<n)-1;i>=0;i--){
                if(!(i>>j&1)) sum[i]+=sum[i^(1<<j)];
            }
        }
        std::cout<<"Case #"<<++_case<<": ";
        for(int i=0;i<m;i++){
            printf("%d",(ans-sum[1<<u[i]|1<<v[i]])/2);
            if(i!=m-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
/*
2
3 3
0 1
0 2
1 2
3 2
0 1
0 2
*/
