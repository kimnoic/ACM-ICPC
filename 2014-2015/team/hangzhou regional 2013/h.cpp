#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define Max 1000000000
int c[22][20],b[20],d[20],dp[1<<22];
int main(){
    int G,B,S;
    int n,t;
    while(scanf("%d%d%d",&G,&B,&S) == 3){
        if(G == 0 && B == 0 && S == 0)break;
        memset(c,0,sizeof(c));
        for(int i = 0;i < B;i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&t);
                c[i][t]++;
            }
        }
        dp[0] = 0;
        int tot = (1<<B);
        for(int i = 1;i < tot;i++){
            dp[i] = -Max;
            for(int j = 1;j <= G;j++)
                b[j] = 0;
            for(int j = 0;j < B;j++)
                if((i&(1<<j)) == 0){
                    for(int k = 1;k <= G;k++){
                        b[k] += c[j][k];
                        while(b[k] >= S)
                            b[k] -= S;
                    }
                }
            for(int j = 0;j < B;j++)
                if(i & (1<<j)){
                    for(int k = 1;k <= G;k++)
                        d[k] = b[k];
                    int u = 0;
                    for(int k = 1;k <= G;k++){
                        d[k] += c[j][k];
                        while(d[k] >= S){
                            d[k] -= S;
                            u++;
                        }
                    }
                    if(u > 0)dp[i] = max(dp[i],u + dp[i^(1<<j)]);
                    else dp[i] = max(dp[i],u - dp[i^(1<<j)]);
                }

        }
        printf("%d\n",dp[tot-1]);
    }
    return 0;
}
