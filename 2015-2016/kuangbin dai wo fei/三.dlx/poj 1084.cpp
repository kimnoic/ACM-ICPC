#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 105
#define Max 23333
#define REP(i,a,n) for(int i=a;i<=n;i++)
int vis[N];
int n,m,K;
struct DLX{
    int n,m,size;
    int U[Max],D[Max],R[Max],L[Max],Row[Max],Col[Max];
    int H[N],S[N],ansd,ans[N];
    void init(int a,int b){
        n=a;
        m=b;
        REP(i,0,m){
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[m]=0;L[0]=0;
        size=m;
        REP(i,1,n) H[i]=-1;
    }
    void link(int r,int c){
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0) H[r]=L[size]=R[size]=size;
        else {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
    void remove(int c){
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i];
    }
    void resume(int c){
        for(int i=U[c];i!=c;i=U[i]){
            L[R[i]]=R[L[i]]=i;
        }
    }
    bool v[Max];
    int f(){
        int ret=0;
        for(int c=R[0];c!=0;c=R[c]) v[c]=true;
        for(int c=R[0];c!=0;c=R[c]){
            if(v[c]){
                ret++;
                v[c]=false;
                for(int i=D[c];i!=c;i=D[i])
                for(int j=R[i];j!=i;j=R[j]){
                    v[Col[j]]=false;
                }
            }
        }
        return ret;
    }
    void Dance(int d){
        if(d+f()>ansd) return ;
        if(R[0]==0){
            if(ansd>d) ansd=d;
            return ;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
                c=i;
        for(int i = D[c];i != c;i = D[i]){
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            Dance(d+1);
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
        return;
    }
};
DLX g;
int ans;
int mp[100][100];
int re[100];
int cnt;
bool judge(int y,int x,int r){

    int a=2*n*(y-1)+x+y-1;//cout<<a<<endl;
    for(int u=0;u<r;u++){
        if(vis[a+u]) return false;
        if(vis[a+u+r*n*2+r]) return false;
        if(vis[a+(2*u+1)*n+u]) return false;
        if(vis[a+(2*u+1)*n+r+u]) return false;
        if(a==8){
            //cout<<a<<" "<<u<<" "<<r<<" "<<n<<endl;
            //cout<<a+u<<endl<<a+u+r*n*2+r<<endl<<a+(2*u+1)*n+u<<endl<<a+(2*u+1)*n+r+u<<endl;
        }
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&n,&m);
        memset(re,0,sizeof(re));
        int cn=0;
        for(int i=1;i<=n;i++){
            cn+=i*i;
        }
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        REP(i,1,m){
            int temp;
            scanf("%d",&temp);
            vis[temp]=1;
        }
        int ans=0;
        for(int r=1;r<=n;r++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(r+i>n+1||r+j>n+1) continue;
                    if(judge(i,j,r)){
                        cnt=(i-1)*n*2+j+i-1;ans++;
                        for(int u=0;u<r;u++){
                            mp[cnt+u][ans]=1;
                            mp[cnt+u+r*n*2+r][ans]=1;
                            mp[cnt+(2*u+1)*n+u][ans]=1;
                            mp[cnt+(2*u+1)*n+r+u][ans]=1;
                        }

                    }

                }
            }
        }
        g.init(2*n*(n+1),ans);
        for(int i=1;i<=2*n*(n+1);i++){
            for(int j=1;j<=ans;j++){
                if(mp[i][j]){
                    //cout<<i<<" "<<j<<endl;
                    g.link(i,j);
                }
            }
        }
        g.ansd=Max;
        g.Dance(0);
        cout<<g.ansd<<endl;
    }
    return 0;
}
