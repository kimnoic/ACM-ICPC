#include <cstdio>
#include <cstring>
#include <algorithm>
int fa[205];
using namespace std;
struct edge{
    int u,v,w;
}e[205*205];
bool cmp(edge a,edge b){
    if (a.w>b.w) return false;
    return true;
}
int find(int x){
    if (fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    int i,j,m,n,k,u,v,w,cnt,ans;
    scanf("%d%d",&n,&m);
    cnt=0;
    for (i=1;i<=n;i++)  fa[i]=i;
        for (i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            e[cnt].u=u;
            e[cnt].v=v;
            e[cnt].w=w;
            cnt++;
        }
    sort(e,e+cnt,cmp);
    k=0;i=0;ans=0;
    while (k<n-1){
        if (i==cnt) break;
        if (find(e[i].u)!=find(e[i].v)){
            k++;
            ans+=e[i].w;
            fa[find(e[i].u)]=find(e[i].v);
        }
        i++;
    }
    printf("%d\n",ans);
    return 0;
}
