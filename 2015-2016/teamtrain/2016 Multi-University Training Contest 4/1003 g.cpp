#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int SIZE = 22;
int rch[1<<SIZE], sum[1<<SIZE], q[1<<SIZE], u[405], v[405];
bool show[1<<SIZE];
inline int lb(int x) {return x&(-x);}

int main() {
    int T;
    scanf("%d",&T);
    for(int cs = 1; cs <= T; cs++) {
        int n, m;
        scanf("%d%d",&n,&m);
        fill(rch , rch + (1<<n) , 0);
        fill(show , show + (1<<n) , 0);
        fill(sum , sum + (1<<n) , 0);
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            ::u[i] = u;
            ::v[i] = v;
            rch[1<<u] |= 1<<v;
            rch[1<<v] |= 1<<u;
        }

        for(int i = 1; i < 1<<n; i++) {
            rch[i] |= rch[i-lb(i)] | rch[lb(i)]; //�������ǰ�㼯�ٽӵĵ�
        }for(int i=0;i<1<<n;i++){
            cout<<i<<" "<<rch[i]<<endl;
        }
        int l = 0, r = 0;
        for(int i = 0; i < n; i++) show[q[r++] = 1<<i] = true;
        //�����ѧ��������bfs
        while(l < r) {
            int c = q[l++]; //��ǰѡ�ĵ㼯
            int left = rch[c] ^ (rch[c] & c); //ʣ�¿ɴ��ûȥ�ĵ㼯
            while(left) {
                int now = lb(left) | c;
                if(!show[now]) show[q[r++] = now] = true;
                left -= lb(left);
            }
        }
        int all = 0;
        for(int i = 0; i < 1 << n; i++) {
            int j = (1 << n) - 1;
            j ^= i;
            if(show[i] && show[j]) {
                sum[i]++;
                all++;
                sum[j]++;
            }
        }
        //all >>= 1;
        for(int j = 0; j < n; j++) {
            for(int i =(1<<n)-1;i>=0;--i) if(!(i>>j&1)) sum[i] += sum[i^(1<<j)];
            //��άǰ׺�ͣ�sum[i]�����i������Ŀ��������i����ͨ�ĵ㼯��Ŀ
        }
        printf("Case #%d: ",cs);
        for(int i = 0; i < m; i++) {
            printf("%d%c",(all - sum[(1<<u[i]) | (1<<v[i])])/2, " \n"[i+1==m]);
            //all��������ͨ�㼯��Ŀ����ȥͬʱ����u��v����ͨ�㼯������ʣ�¾�����(u,v)Ϊ��ĵ㼯��Ŀ������
        }
    }

}
