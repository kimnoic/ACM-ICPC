#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 666;
int d[N][N], a[N][N], n, m;
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(a, 0x3f, sizeof(a)); //��ʼ��
		memset(d, 0x3f, sizeof(d));
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            d[u][v] = d[v][u] = w;
            a[u][v] = a[v][u] = w;
        }
        int ans = 0x7fffffff;
        for (int k = 1; k <= n; k++)    //�м�ڵ����������
            {
                //��ʱ��d[i][j]һ��û�о���k���¹�
                for(int i =  1; i <= k - 1; i++)
                    for(int j = 1; j <= k - 1; j++)
                        ans = min(ans, d[i][j] + a[i][k] + a[k][j]);//ע��map��d��Ӧ��

                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }

        printf("%d\n", ans);
    }
    return 0;
}
