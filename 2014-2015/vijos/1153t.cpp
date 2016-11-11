#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 210
#define INF 987654321
using namespace std;
int dp[N][8100];
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int a[N], sum = 0, ans = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            //dp[i][0] = 1;
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = n / 2; j >= 1; j--)
                for(int k = 8000; k >= 0; k--) if(dp[j - 1][k]) dp[j][k + a[i]] = 1;
        }
        for(int i = sum / 2; i >= 0; i--) if(dp[n / 2][i]) {
            ans = i;
            break;
        }
        //cout<<sum<<endl;
        if(ans > sum - ans) printf("%d %d\n", sum - ans, ans);
        else printf("%d %d\n", ans, sum - ans);
    }
}
