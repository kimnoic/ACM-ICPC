#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k, dp[100005], seg[400001], v[100005];
char s[100002];
int at, val;
void update(int n, int s, int e){
    if (at<s || at>e)
        return;
    if (s == e){
        seg[n] = at;
        v[at] = val;
        return;
    }
    update(n * 2, s, (s + e) / 2);
    update(n * 2 + 1, (s + e) / 2 + 1, e);
    if (v[seg[n * 2]]<v[seg[n * 2 + 1]])
        seg[n] = seg[n * 2];
    else
        seg[n] = seg[n * 2 + 1];
}
int l, r;
int get(int n, int s, int e){
    if (l>e || r<s)
        return 0;
    if (s >= l && e <= r)
        return seg[n];
    int a = get(n * 2, s, (s + e) / 2);
    int b = get(n * 2 + 1, (s + e) / 2 + 1, e);
    if (a == 0)return b;
    if (b == 0)return a;
    if (v[a]<v[b])
        return a;
    return b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for (int i = 0; i<4 * n; ++i)
            seg[i] = 0;
        int next = 1e9;
        dp[n + 1] = 0;
        val = 0;
        at = n;
        update(1, 1, n + 1);
        for (int i = n; i > 0; --i){
            dp[i] = 1 + dp[i + 1];
            if (s[i + 1] == s[i])
                next = i + 1;
            l = next;
            r = min(n + 1, i + k - 1);
            if (l <= r){
                int x = get(1, 1, n + 1);
                dp[i] = min(dp[i], 1 + v[x]);
            }
            at = i - 1;
            val = dp[i];
            update(1, 1, n + 1);
        }
        printf("%d\n", dp[1] - 1);
    }
    return 0;
}
