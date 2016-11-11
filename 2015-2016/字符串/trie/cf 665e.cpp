#include <bits/stdc++.h>
const int maxn=1e7+10;
int sum[maxn],v[maxn<<1],n,k,sz;
long long ans;
int tr[maxn<<1][2];
void add(int x){
    int u=0;
    for(int i=30;i>=0;i--){
        int c=(x>>i)&1;
        if(!tr[u][c]){
            tr[u][c]=sz++;
        }
        v[tr[u][c]]++;
        u=tr[u][c];
    }
}
int query(int x){
    int res=0;
    int u=0,sum=0;
    for(int i=30;i>=0;i--){
        int c=(x>>i)&1;
        if(sum+(1<<i)>=k){
            res+=v[tr[u][c^1]];
            u=tr[u][c];
            if(!u) break;
        }
        else {
            sum += 1<<i;
            u=tr[u][c^1];
            if(!u) break;
        }
    }
    return res;
}
int main(){
    std::cin>>n>>k;
    sum[0]=0;
    ans=0;
    sz=1;
    int temp;
    add(0);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        sum[i]=sum[i-1]^temp;
        ans+=(long long)query(sum[i]);
        add(sum[i]);
//        std::cout<<ans<<std::endl;
    }
    std::cout<<ans;
    return 0;
}
