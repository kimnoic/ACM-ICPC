#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
char t[maxn];
long long dp[maxn][maxn];
int T;
int main(){
    cin>>T;
    while(T--){
        scanf("%s",t+1);
        int len=strlen(t+1);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len;i++) dp[i][i]=1;
        for(int i=1;i<len;i++){
            for(int j=1;j+i<=len;j++){
                if(t[j]==t[j+i]){
                    dp[j][j+i]=dp[j+1][j+i]+dp[j][j+i-1]+1;
                }
                else {
                    dp[j][j+i]=dp[j+1][j+i]+dp[j][j+i-1]-dp[j+1][j+i-1];
                }
            }
        }
        printf("%lld\n",dp[1][len]);
    }
    return 0;
}
