#include <bits/stdc++.h>

using namespace std;
int fa[200100];
int Find(int x){
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
vector<int> col[200100];

map<int,int> mp;
int n,m,k;
int a[200100];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        int X=Find(u);
        int Y=Find(v);
        if(X!=Y) fa[X]=Y;
    }
    for(int i=1;i<=n;i++) int X=Find(i);
    for(int i=1;i<=n;i++){
        col[fa[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(col[i].size()==1) continue;
        int m=col[i].size();
        mp.clear();
        int mx=0;
        for(int j=0;j<m;j++){
            int x=col[i][j];
            mp[a[x]]++;
            mx=max(mp[a[x]],mx);
        }
        ///printf("m=%d mx=%d\n",m,mx);
        ans+=m-mx;
    }
    cout<<ans<<endl;
    return 0;
}
