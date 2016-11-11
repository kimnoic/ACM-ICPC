#include <bits/stdc++.h>

using namespace std;

const int maxn = 50010;
struct pt{
    int l,r,id;
    long long a,b;
}p[maxn];
int n,m,blocks,c[maxn];
long long sum[maxn];
bool cmp(pt a,pt b){
    if(a.l/blocks!=b.l/blocks) return a.l/blocks<b.l/blocks;
    else return a.r<b.r;
}
long long ans;
void update(int d,int num){
    ans-=sum[c[d]]*sum[c[d]];
    sum[c[d]]+=num;
    ans+=sum[c[d]]*sum[c[d]];
}
long long gcd(long long a,long long b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void solve(){
    ans=0;
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(R<p[i].r){
            update(R+1,1);
            R++;
        }
        while(R>p[i].r){
            update(R,-1);
            R--;
        }
        while(L<p[i].l){
            update(L,-1);
            L++;
        }
        while(L>p[i].l){
            update(L-1,1);
            L--;
        }
        if(p[i].l==p[i].r){
            p[i].a=0;p[i].b=1;
            continue;
        }
        p[i].a=ans-(p[i].r-p[i].l+1);
        p[i].b=(long long)(p[i].r-p[i].l+1)*(p[i].r-p[i].l);
        long long k=gcd(p[i].a,p[i].b);
        p[i].a/=k;
        p[i].b/=k;
    }
}
bool cmp2(pt a,pt b){
    return a.id<b.id;
}
void print(){
    //if(n<49900)
    sort(p+1,p+m+1,cmp2);
    for(int i=1;i<=m;i++){
        printf("%lld/%lld\n",p[i].a,p[i].b);//<<p[i].a<<"/"<<p[i].b<<endl;
    }
}
int main(){
//    cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
//        cin>>c[i];
    }
    for(int i=1;i<=m;i++){
        p[i].id=i;
        scanf("%d%d",&p[i].l,&p[i].r);
//        cin>>p[i].l>>p[i].r;
    }
    blocks=(int)sqrt(n);
    sort(p+1,p+m+1,cmp);
    solve();
    print();
    return 0;
}
