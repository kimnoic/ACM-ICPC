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
#define Max N*N+N
#define REP(i,a,n) for(int i=a;i<=n;i++)
int n,m;
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
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])
        for(int j=R[i];j!=i;j=R[j]){
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            --S[Col[j]];
        }
    }
    void resume(int c){
        for(int i=U[c];i!=c;i=U[i]){
            for(int j=L[i];j!=i;j=L[j]){
                ++S[Col[U[D[j]]=D[U[j]]=j]];
            }
        }
        L[R[c]]=R[L[c]]=c;
    }
    bool Dance(int d){
        if(R[0]==0){
            ansd=d;
            return true;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[c])
                c=i;
        remove(c);
        for(int i = D[c];i != c;i = D[i]){
            ans[d] = Row[i];
            for(int j = R[i];j != i;j = R[j])remove(Col[j]);
            if(Dance(d+1))return true;
            for(int j = L[i];j != i;j = L[j])resume(Col[j]);
        }
        resume(c);
        return false;
    }
};
DLX a;
int main(){
    while(~scanf("%d%d",&n,&m)){
        a.init(n,m);
        REP(i,1,n){
            int t;
            scanf("%d",&t);
            while(t--){
                int b;
                scanf("%d",&b);
                a.link(i,b);
            }
        }
        if(!a.Dance(0)) cout<<"NO"<<endl;
        else{
            printf("%d",a.ansd);
            REP(i,0,a.ansd-1){
                printf(" %d",a.ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

