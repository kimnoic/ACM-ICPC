#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000200;
int fac[maxn],cnt,cov[maxn],c[maxn],v[maxn],ju[maxn];
int tol;
int n,k;
void init(){
    scanf("%d%d",&n,&k);
    for(int i=2;i<=k;++i){
      if(k%i)continue;
       int cur=1;
       while(k%i==0)cur*=i,k/=i;
       fac[++cnt]=cur;
    }
    for(int i=0;i<n;++i){
      int x;scanf("%d",&x);
      for(int j=1;j<=cnt;++j)
        if(x%fac[j]==0)cov[j]=true;
    }
    bool flag=1;
    for(int i=1;i<=cnt;++i)
      if(!cov[i])flag=0;
    if(flag)printf("Yes\n");
    else printf("No\n");

}
int main(){
    init();
    return 0;
}
