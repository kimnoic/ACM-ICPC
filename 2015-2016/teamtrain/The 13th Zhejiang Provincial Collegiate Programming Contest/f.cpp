#include <bits/stdc++.h>
using namespace std;
#define Max 100010
#define LL long long
#define N 20
struct Node{
    LL l,r;
}a[20],b[N];
bool cmp(Node a,Node b){
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

long long m,k,res;
int cnt;
void dfs(LL pos,int i,long long ans,long long n){
    if(n>m)
        return;
    if((i>=cnt+1)||n==m){
        res=max(res,ans);
        return;
    }
    long long len,pos1,num,p2,p;
    if(pos<b[i].r){
        len=min(b[i].r-b[i].l+1,b[i].r-pos);
        p=len%k;
        if(p==0)
            p2=len/k;
        else p2=len/k+1;
        if(p2+n>m) res=max(res,ans+(m-n)*k);
        pos1=max(b[i].l+p2*k-1,pos+p2*k);
        num=p2*k;
        dfs(pos1,i+1,ans+num,n+p2);
        dfs(b[i].r+k-1,i+1,ans+num+b[i].r+k-1-pos1,n+p2+1);
    }
    else if(pos>=b[i].r){
        dfs(pos,i+1,ans,n);
        dfs(b[i].r+k-1,i+1,ans+b[i].r+k-1-pos,n+1);
    }
}
int T;
int n;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>m;
        for(int i=1;i<=n;i++)
             scanf("%lld%lld",&a[i].l,&a[i].r);
        sort(a+1,a+n+1,cmp);
        cnt=0;
        int i,j;
        for(i=1;i<=n;i){
            for(j=i+1;j<=n;j++){
                if(a[j].l<=a[i].r+1){
                    a[i].r=max(a[i].r,a[j].r);
                }
                else break;
            }
            b[++cnt]=a[i];
            i=j;
        }
        res=0;
        dfs(0,1,0,0);
        cout<<res<<endl;
    }
    return 0;
}


