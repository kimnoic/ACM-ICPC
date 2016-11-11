#include <bits/stdc++.h>
const int maxn=2e5+10;
struct pt{
    int v,p;
}p[maxn];
int c[maxn],n;
int l[maxn],r[maxn];
int blmin[maxn],blmax[maxn];
int brmin[maxn],brmax[maxn];
int ll[maxn],rr[maxn];
bool cmp1(pt a,pt b){
    if(a.v==b.v)
        return a.p<b.p;
    return a.v<b.v;
}
bool cmp2(pt a,pt b){
    if(a.v==b.v)
        return a.p>b.p;
    return a.v>b.v;
}
int lowbit(int x){
    return x&(-x);
}
void update(int x){
    while(x<=n){
        c[x]+=1;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
long long ans;
int main(){
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i].v);
            p[i].p=i;
        }
        p[n+1].v=0;
        p[0].v=0;
        std::sort(p+1,p+n+1,cmp1);
        long long ans1=0,ans2=0;
        int f=0;
        l[1]=1;
        for(int i=1;i<=n;i++){
            if(p[i].v==p[i-1].v){
                l[i]=l[i-1];
            }
            else {
                l[i]=i;
            }
        }
        for(int i=1;i<=n;i++){
            update(p[i].p);
            if(p[i].v==p[i-1].v) f++;
            else f=0;
            //ans+=(long long)getsum(l[p[i].p]-1)*(getsum(n)-getsum(r[p[i].p]));
            ans1+=getsum(p[i].p-1);
            ans1-=f;
            ans2+=getsum(n)-getsum(p[i].p);
            blmin[p[i].p]=getsum(p[i].p-1)-f;
            brmin[p[i].p]=l[p[i].p]-1-blmin[p[i].p];
        }
//        std::cout<<ans1<<" "<<ans2<<std::endl;
        ans=ans1*ans2;
        //std::cout<<ans<<std::endl;
        std::sort(p+1,p+n+1,cmp2);
        memset(c,0,sizeof(c));
        r[n]=1;
        for(int i=n-1;i>=1;i--){
            if(p[i].v==p[i+1].v){
                r[i]=r[i+1];
            }
            else r[i]=n-i+1;
        }
        f=0;
        for(int i=1;i<=n;i++){
            update(p[i].p);
            if(p[i].v==p[i+1].v) f++;
            else f=0;
            brmax[p[i].p]=getsum(n)-getsum(p[i].p)-f;
            blmax[p[i].p]=r[p[i].p]-1-brmax[p[i].p];
        }
//        std::cout<<brmax[2]<<" "<<blmax[2]<<std::endl;
//        for(int i=1;i<=n;i++){
//            std::cout<<blmax[i]<<" "<<brmax[i]<<std::endl;
//        }
        for(int i=1;i<=n;i++){
            //std::cout<<blmax[i]<<std::endl;
            ans-=(long long)(brmax[i]*brmin[i]);
            ans-=(long long)(blmax[i]*blmin[i]);
            ans-=(long long)(brmin[i]*blmin[i]);
            ans-=(long long)(blmax[i]*brmax[i]);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
