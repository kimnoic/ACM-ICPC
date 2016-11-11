#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdio.h>
using namespace std;
typedef long long LL;
#define N 200010
#define lowbit(x) (x&(-x))

int n;
int a[N], b[N];
int f[N], c[N];

inline void scand(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9')
        ;
    while (c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'), c = getchar();
}

void add(int x, int y)
{
    while (x <= n) {
        c[x] += y;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int res = 0;
    while (x)
		{
        res += c[x];
        x -= lowbit(x);
		}
    return res;
}

void init()
{
    memset(c, 0, sizeof (c));
    for (int i = 1; i <= n; i++) add(i, 1);
}

int main() {
    scand(n);
    for (int i = 1; i <= n; i++)
	{
        scand(a[i]);
        a[i]++;
	}
    for (int i = 1; i <= n; i++)
    {
        scand(b[i]);
        b[i]++;
    }
    init();
    for (int i = 1; i < n; i++) {
        int les = sum(a[i] - 1);
        f[n - i] += les;
        add(a[i], -1);
    }
    init();
    for (int i = 1; i < n; i++)
    {
        int les = sum(b[i] - 1);
        f[n - i] += les;
        add(b[i], -1);
    }
    for (int i = 1; i < n; i++)
    {
        f[i + 1] += f[i] / (i + 1);
        f[i] = f[i] % (i + 1);
    }
    init();
    int sml = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        int l = 1, r = n, mid, tmp, ans = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            tmp = sum(mid - 1);
            if (tmp <= f[i])
            {
                l = mid + 1;
                ans = mid;
            } else
            {
                r = mid - 1;
            }
        }
        if (ans == -1)
        {
            ans = sml;
        }
		cout<<ans-1<<" ";
        add(ans, -1);
        while (!c[sml]) sml++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
        {
        	cout<<i-1<<endl;
            break;
        }
    }
    return 0;
}
