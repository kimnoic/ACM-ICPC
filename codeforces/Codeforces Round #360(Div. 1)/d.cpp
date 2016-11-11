#include <bits/stdc++.h>
using namespace std;
int n,m,q;
const int maxn = 1010;
int fa[maxn*2];
struct edge{
    int u,v,w,id;
}p[maxn*maxn];
bool cmp(edge a,edge b){
    return a.w>b.w;
}
int findf(int u){
    if(u==fa[u]) return u;
    else return fa[u]=findf(fa[u]);
}
void uni(int u,int v){
    int fau=findf(u);
    int fav=findf(v);
    if(fau!=fav) fa[fau]=fav;
}
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
        //cin>>p[i].u>>p[i].v>>p[i].w;
        p[i].id=i;
    }
    sort(p+1,p+m+1,cmp);
    while(q--){
        int l,r;
        cin>>l>>r;
        int flag=0;
        for(int i=0;i<=2*n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            if(p[i].id>=l&&p[i].id<=r){
                if(findf(p[i].u)==findf(p[i].v)){
                    cout<<p[i].w<<endl;
                    flag=1;
                    break;
                }
                else {
                    uni(p[i].u+n,p[i].v);
                    uni(p[i].v+n,p[i].u);
                }
            }
        }
        if(!flag)cout<<-1<<endl;
    }
    return 0;
}
