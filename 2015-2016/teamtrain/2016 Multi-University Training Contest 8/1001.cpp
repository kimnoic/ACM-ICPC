#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+10;
int a[maxn],b[maxn],n,m;
int aa[maxn],bb[maxn];
int vis[maxn];
int nxt[maxn];
int T;
struct pt{
    int l,r,id;
    int ll,rr;
    int flag;
}p[maxn];
int v[maxn][maxn],vv[maxn][maxn];
int st[maxn];
bool solve(){
    for(int i=1;i<=n;i++){
        cout<<i<<endl;
        int mxx=i;
        int top=0;
        memset(st,0,sizeof(st));
        if(i<=nxt[i]){
            for(int j=1;j<=m;j++){
                if(p[j].ll<=mxx&&p[j].rr>=mxx&&(!p[j].flag)){
                    mxx=max(p[j].rr,mxx);
                    st[++top]=j;
                    if(mxx>=nxt[i]){
                        for(int k=1;k<top;k++){
                            if(k==1){
                                int pre=st[k];
                                int nex=st[k+1];
                                int pos=p[nex].ll;
                                vv[pre][i]=1;
                                while(v[pre][pos]||vv[nex][pos]){
                                    pos++;
                                }
                                if(pos>p[pre].rr){
                                    return false;
                                }
                                v[pre][pos]=1;
                                vv[nex][pos]=1;
                                while(v[pre][p[pre].ll]){
                                    p[pre].ll++;
                                }
                                while(v[pre][p[pre].rr]){
                                    p[pre].rr--;
                                }
                                if(p[pre].ll>p[pre].rr){
                                    p[pre].flag=1;
                                }
                            }
                            else {
                                int pre=st[k];
                                int nex=st[k+1];
                                int pos=p[nex].ll;
                                while(v[pre][pos]||vv[nex][pos]){
                                    pos++;
                                }
                                if(pos>p[pre].rr){
                                    return false;
                                }
                                v[pre][pos]=1;
                                vv[nex][pos]=1;
                                while(v[pre][p[pre].ll]){
                                    p[pre].ll++;
                                }
                                while(v[pre][p[pre].rr]){
                                    p[pre].rr--;
                                }
                                if(p[pre].ll>p[pre].rr){
                                    p[pre].flag=1;
                                }
                            }
                        }
                        if(v[st[top]][nxt[i]]||p[st[top]].rr<nxt[i]){
                            return false;
                        }
                        else {
                            v[st[top]][nxt[i]]=1;
                            break;
                        }
                    }
                }
                if(j==m){
                    return false;
                }
            }
        }
        else {
            for(int j=1;j<=m;j++){
                    if(p[j].ll<=mxx&&p[j].rr>=mxx&&(!p[j].flag)){
                    mxx=min(p[j].ll,mxx);
                    st[++top]=j;
                    if(mxx<=nxt[i]){
                        for(int k=1;k<top;k++){
                            if(k==1){
                                int pre=st[k];
                                int nex=st[k+1];
                                int pos=p[nex].rr;
                                vv[pre][i]=1;
                                while(v[pre][pos]||vv[nex][pos]){
                                    pos--;
                                }
                                if(pos<p[pre].ll){
                                    return false;
                                }
                                v[pre][pos]=1;
                                vv[nex][pos]=1;
                                while(v[pre][p[pre].ll]){
                                    p[pre].ll++;
                                }
                                while(v[pre][p[pre].rr]){
                                    p[pre].rr--;
                                }
                                if(p[pre].ll>p[pre].rr){
                                    p[pre].flag=1;
                                }
                            }
                            else {
                                int pre=st[k];
                                int nex=st[k+1];
                                int pos=p[nex].rr;
                                while(v[pre][pos]||vv[nex][pos]){
                                    pos--;
                                }
                                if(pos<p[pre].ll){
                                    return false;
                                }
                                v[pre][pos]=1;
                                vv[nex][pos]=1;
                                while(v[pre][p[pre].ll]){
                                    p[pre].ll++;
                                }
                                while(v[pre][p[pre].rr]){
                                    p[pre].rr--;
                                }
                                if(p[pre].ll>p[pre].rr){
                                    p[pre].flag=1;
                                }
                            }
                        }
                        if(v[st[top]][nxt[i]]||p[st[top]].ll>nxt[i]){
                            return false;
                        }
                        else {
                            v[st[top]][nxt[i]]=1;
                            break;
                        }
                    }
                }
                if(j==m) return false;
            }
        }
    }
    return true;
}
int main(){
    std::cin>>T;
    while(T--){
        cin>>n>>m;
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        memset(nxt,0,sizeof(nxt));
        memset(v,0,sizeof(v));
        memset(vv,0,sizeof(vv));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            p[i].flag=0;
        }
        for(int i=1;i<=n;i++) {
            std::cin>>a[i];
            aa[a[i]]++;
        }
        for(int i=1;i<=n;i++) {
            std::cin>>b[i];
            bb[b[i]]++;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(aa[i]!=bb[i]){
                flag=1;
                break;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    if(a[i]==b[j]){
                        nxt[i]=j;
                        vis[j]=1;
                        break;
                    }
                }
            }
        }

        for(int i=1;i<=m;i++){
            scanf("%d%d",&p[i].l,&p[i].r);
            p[i].ll=p[i].l;
            p[i].rr=p[i].r;
        }
        if(flag){
            printf("No\n");
            continue;
        }
        if(solve()){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
/*
1
4 2
1 0 0 0
0 0 0 1
1 3
3 4
*/
