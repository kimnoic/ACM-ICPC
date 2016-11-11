#include <bits/stdc++.h>
int T;
const int maxn=50;
#define INF 0x3f3f3f3f

long long p,q,res;
long long sum,day,re[maxn];
long long po[maxn];
int len;
void init(){
    po[0]=0;po[1]=1;
    for(int i=2;i<=33;i++){
        po[i]=po[i-1]*2+1;
    }
}

void solve(){
    sum=0,day=0;
    long long ans=INF;
    while(1){
        res=p-q;
        int pos=std::lower_bound(po,po+33,res)-po;
//    std::cout<<pos<<" "<<po[pos]<<std::endl;
        long temp=p-po[pos];if(temp<0) temp=0;
        long left=q-temp-day;if(left<0) left=0;
        ans=std::min(ans,pos+left+day+sum);
        if(po[pos]>res) pos--;
        sum+=pos;
        p-=po[pos];
        if(p==q){
            ans=std::min(ans,day+sum);
            break;
        }
        day++;
    }
    printf("%I64d\n",ans);
}
int main(){
    init();
    std::cin>>T;
    while(T--){
        scanf("%lld%lld",&p,&q);
        if(p<=q){
            printf("%I64d\n",q-p);
        }
        else {
//            res=p-q;
            solve();
        }
    }
    return 0;
}

