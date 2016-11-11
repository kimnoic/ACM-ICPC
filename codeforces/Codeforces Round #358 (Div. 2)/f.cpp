#include <bits/stdc++.h>
using namespace std;
const int maxn = 1023;
int dp[maxn][maxn];
int f[maxn][maxn][11][2];
char s1[maxn],s2[maxn];int n,m,k;
int cnt=0;
void init(){
    cin>>n>>m>>k;
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=0;
        }
    }
}
void solve(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;l<=k;l++){
                int temp=dp[i][j];
                if(temp) f[i][j][l][0]=f[i-temp][j-temp][l-1][1]+temp;
                else f[i][j][l][0]=0;
                cnt++;
                f[i][j][l][1]=max(f[i][j][l][1],f[i-1][j][l][1]);
                f[i][j][l][1]=max(f[i][j][l][1],f[i][j-1][l][1]);
                f[i][j][l][1]=max(f[i][j][l][1],f[i-1][j-1][l][1]);
                f[i][j][l][1]=max(f[i][j][l][1],f[i][j][l][0]);
                ans=max(ans,(long long)f[i][j][l][1]);
            }
        }
    }
    if(cnt)
    cout<<ans;
    else cout<<0;
}
int main(){
    init();
    solve();
    return 0;
}
