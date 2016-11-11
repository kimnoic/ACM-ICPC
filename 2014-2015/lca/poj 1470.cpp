#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 2001

int n,fa[MAXN];
int rank[MAXN];
int indegree[MAXN];
int vis[MAXN];
vector<int> hash[MAXN],Qes[MAXN];
int ances[MAXN];//����
int res[MAXN];

void init()
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        indegree[i]=0;
        vis[i]=0;
        ances[i]=0;
        hash[i].clear();
        Qes[i].clear();
        res[i]=0;
    }
}

int find(int x)
{
    if(x != fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
void Tarjan(int u)
{
    ances[u]=u;
    for(int i=0;i<hash[u].size();i++)
    {
        Tarjan(hash[u][i]);//�ݹ鴦�����
        fa[hash[u][i]]=u;
    }
    vis[u]=1;

    //��ѯ
    for(int i=0;i<Qes[u].size();i++)
    {
        if(vis[Qes[u][i]]==1)//����ѯ����һ����㿪ʼ�Ѿ����ʹ�����ǰ��u�ڴ˻غϷ��ʡ�
        {
            //cout<<u<<" "<<Qes[u][i]<<" "<<ances[find(Qes[u][i])]<<endl;
            res[find(Qes[u][i])]++;//���ڵݹ飬��ʱ������u
        }
    }
}
int a,b,c;
char aa,bb,cc;
int m;
int main()
{
    while(cin>>n){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d:(%d)",&a,&b);
            for(int j=1;j<=b;j++){
                scanf(" %d",&c);
                hash[a].push_back(c);
                indegree[c]++;
            }
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            scanf(" (%d %d)",&a,&b);
            Qes[a].push_back(b);
            Qes[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                Tarjan(i);
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(res[i]){
                printf("%d:%d\n",i,res[i]);
            }
        }
    }
    return 0;
}
