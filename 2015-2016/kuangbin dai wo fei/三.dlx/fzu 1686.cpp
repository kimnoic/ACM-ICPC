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
#define N 21*21
#define Max 235*235
#define INF 0x3fffffff
#define REP(i,a,n) for(int i=a;i<=n;i++)
int mp[N][N];
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
        if(d+f()>=ansd) return;
        if(R[0]==0){
            if(d<ansd) ansd=d;
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
    }
};
DLX g;
int n1,m1;
int t;
int main(){
    while(scanf("%d %d",&n,&m)==2){
        memset(mp,0,sizeof(mp));
        int cnt=0;
        REP(i,0,n-1){
            REP(j,0,m-1){
                scanf("%d",&t);
                if(t){
                    g.link(i,j);
                    mp[i][j]=++cnt;
                }
            }
        }
        g.init(n*m,cnt);
        cnt=1;
        scanf("%d%d",&n1,&m1);
        REP(i,0,n-1){
            REP(j,0,m-1){
                for(int x=0;x<n1&&x+i<n;x++){
                    for(int y=0;y<m1&&y+j<m;y++){
                        if(mp[i+x][j+y]){
                            g.link(cnt,mp[i+x][j+y]);
                        }
                    }
                }
                cnt++;
            }
        }
        g.ansd=INF;
        g.Dance(0);
        printf("%d\n",g.ansd);
    }
    return 0;
}
