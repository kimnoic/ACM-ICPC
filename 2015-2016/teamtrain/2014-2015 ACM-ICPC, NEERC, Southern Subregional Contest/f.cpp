#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}

struct node{
    int x, y;
};

int f[N * 2];
long long sum[N * 2];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    memset(f, 0, sizeof(f));
    memset(sum, 0, sizeof(sum));

    int i;
    for (i = 1; i <= n; i++){
        scanf("%d", &f[i]);
        sum[i] = sum[i - 1] + f[i];
    }


    if (2 * k >= n){
        printf("%I64d\n", sum[n]);
        return 0;
    }

    long long maxx = 0, maxy = 0;
    for (i = k; i <= n; i++){
        if (sum[i] - sum[i - k] >= maxx){
            maxx = sum[i] - sum[i - k];
        }
        maxy = max(maxy, maxx + sum[i + k] - sum[i]);
    }

    cout<<maxy;
    return 0;
}
