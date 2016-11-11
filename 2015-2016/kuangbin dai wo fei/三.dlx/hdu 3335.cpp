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
#define N 1005
#define Max N*N
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
        //if(d+f()>ansd) return ;
        if(R[0]==0){
            if(ansd<d) ansd=d;
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
long long num[Max];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i];
        }
        g.init(n,n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(num[i]%num[j]==0||num[j]%num[i]==0) g.link(i,j);
            }
        }
        g.ansd=0;
        g.Dance(0);
        cout<<g.ansd<<endl;
    }
    return 0;
}

























