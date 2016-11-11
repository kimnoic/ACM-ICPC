#include <bits/stdc++.h>
using namespace std;
const int maxn = 500100;
vector<int>rt[maxn];

int mxs[maxn],f[maxn];
int sum[maxn],rec[maxn];
void dfs(int u) {
    sum[u]=1;
    int k=-1;
    for(int i=0;i<rt[u].size();i++){
        dfs(rt[u][i]);
        sum[u]+=sum[rt[u][i]];
        if(mxs[u]<=sum[rt[u][i]]){
            mxs[u]=sum[rt[u][i]];
            k=rt[u][i];
        }
    }
    if(sum[u]<2*mxs[u]){
        int son=rec[k];
        int mson=k;
        while(son!=k){
            int t=max(mxs[son],sum[u]-sum[son]);
            if(2*t<=sum[u]){
                mson=son;
                break;
            }
            son=f[son];
        }
        rec[u]=mson;
    }
    else{
        rec[u]=u;
        return ;
    }
}

int n,T;
int u;
int main(){
    cin>>n>>T;
    for(int i=1;i<n;i++){
        scanf("%d",&u);
        f[i+1]=u;
        rt[u].push_back(i+1);
    }
    dfs(1);
    while(T--){
        scanf("%d",&u);
        printf("%d\n",rec[u]);
        //cout<<res[u]<<endl;
    }
    return 0;
}
