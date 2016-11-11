//�ж���С�������Ƿ�Ψһ
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 0x3fffffff;
const int N = 106;
const int M = 10006;
struct Edge{
    int x, y, val, mst, next;
    void set(int a, int b, int w, int flag){
        x = a; y = b; val = w; mst = flag;
    }
} e[M];
vector <Edge> st[N];
int fa[N], n, m, w, x, y, MST;
bool cmp (const Edge &a, const Edge &b){
          return a.val < b.val;
}
int father(int x){
    if(fa[x] == x) return x;
    return fa[x] = father(fa[x]);
}
int Kruskal(int tot)
{//һ��tot���ߣ���0 - (tot-1)
    int sum = 0, fx, fy;
    Edge temp;
    sort (e, e + tot, cmp);
    int tj = 0;
    for(int i = 0 ; i < tot; ++i){
        fx = father(e[i].x);
        fy = father(e[i].y);
        if(fx == fy) continue;
        fa[fx] = fy;
        sum += e[i].val;
        e[i].mst = 1;
        tj ++;
//����С�������еı�����һ����ͼ������ͼ��ȥɾ��
        temp.set(e[i].x, e[i].y, e[i].val, 1);
        st[e[i].x].push_back(temp);
        temp.set(e[i].y, e[i].x, e[i].val, 1);
        st[e[i].y].push_back(temp);
    }
    if(tj < n - 1) return -1; //ͼ����ͨ
    return sum;
}
int dfs(int x, int T, int fa)
{//����С������ͼ�нڵ�x��T�е�����Ȩ
    if(x == T) return -INF + 1;
    for(unsigned int i = 0; i < st[x].size(); i++)
        if(st[x][i].y != fa)
    {
        int temp = dfs(st[x][i].y, T, x);
        if(temp != -INF)
            return max(st[x][i].val, temp);
    }
    return - INF;
}
int cal(int tot)
{//tot Ϊ����
    int SMST = INF;
    for(int i = 0; i < tot; i++)
        if(!e[i].mst)
    {//ö�ٲ�����С�������ϵıߣ��γɻ���
//��������ҵ���Ȩ���ıߣ���������ӵ������±ߣ�
        int maxt = dfs(e[i].x, e[i].y, 0);
        int temp = MST + e[i].val - maxt;
        SMST = min(SMST, temp);//���´�С��������ֵ
    }
    return SMST;
}
int main ()
{
    freopen("test.in", "r", stdin);
    int Test;
    scanf("%d", &Test);
    while(Test --){
        scanf("%d%d", &n , &m);
        for(int i = 0; i <= n; ++i)
            fa[i] = i;
        memset(e, 0, sizeof(e));
        memset(st, 0, sizeof(st));
        for (int i = 0; i < m; ++i){
            scanf ("%d%d%d", &x, &y, &w);
            e[i].set(x, y, w, 0);
        }
        MST = Kruskal(m);
        int SMST = cal(n);//���С������
        if(MST < 0){
            printf("0\n");continue;
        }
        if(SMST > MST)
            printf("%d\n", MST);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
