#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAXN = 100100;
const int CHECK = 50;
string a[MAXN];
std::random_device rnd;
ll mod[CHECK], p[CHECK], sum[CHECK];

bool solve() {
    int n, k;
    cin >> n >> k;
    int turn = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        if (a[i] == "?") turn++;
    }
    if (k == 0) {
        if (a[0] == "0") return true;
        if (a[0] == "?") return (n+1-turn)%2 == 1;
        return false;
    }
    if (turn == 0) {
        for (int i = 0; i < CHECK; i++) {
            mod[i] = 1000000000+rnd()%1000000;
            if (mod[i]%2==0) mod[i]++;
            p[i] = 1;
        }
        for (int i = 0; i <= n; i++) {
            ll num = 0;
            if (a[i][0] == '-') {
                for (int j = 1; j < a[i].size(); j++)
                    num = 10*num+(a[i][j]-'0');
                num *= -1;
            } else {
                for (char c : a[i]) {
                    num = 10*num+(c-'0');
                }
            }
            for (int j = 0; j < CHECK; j++) {
                sum[j] += p[j]*num%mod[j];
                sum[j] %= mod[j];
                (p[j] *= k) %= mod[j];
            }
        }
        for (int i = 0; i < CHECK; i++) {
            if (sum[i]) return false;
        }
        return true;
    }
    if ((n+1)%2==0) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
