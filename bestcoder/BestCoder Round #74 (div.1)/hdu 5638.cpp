#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
const int mod=1e9+7;
int T,n,m,k,cnt[maxn],x,y,vis[maxn];
vector<int> t[maxn];

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=n;i++) t[i].clear(),cnt[i]=vis[i]=0;
        while (m--){
            scanf("%d%d",&x,&y);
            t[x].push_back(y);
            cnt[y]++;
        }
        priority_queue<int,vector<int>,greater<int> > p;
        for (int i=1;i<=n;i++) if (cnt[i]<=k) p.push(i),vis[i]=1;
        int res=0,i=1;
        while (!p.empty()){
            int q=p.top();  p.pop();
            if (cnt[q]>k) {vis[q]=0; continue;}
            (res+=(LL)q*i++%mod)%=mod;
            k-=cnt[q];
            for (int i=0;i<t[q].size();i++){
                cnt[t[q][i]]--;
                if (!vis[t[q][i]]&&cnt[t[q][i]]<=k){
                    p.push(t[q][i]);
                    vis[t[q][i]]=1;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
