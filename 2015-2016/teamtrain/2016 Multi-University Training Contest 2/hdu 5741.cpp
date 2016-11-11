#include <bits/stdc++.h>
const int maxn=1020;
const int maxm=maxn*maxn;
const int inf=2e9;
#define MP std::make_pair
std::pair<int,int>l[maxm],h[maxm];
int lcnt,m,hcnt,v[maxn],n;
char ans[maxm];
int main(){
//    freopen("H.in","r",stdin);
//    freopen("H.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",v+i);
        }
        lcnt=0,hcnt=0;
        for(int i=1;i<=n;i++){
            int x=0,y=0;
            for(int j=i;j<=n;j++){
                if(j&1){
                    x+=v[j];
                }
                else {
                    y+=v[j];
                }
                if(i&1 && j&1){
                    l[++lcnt]=MP(x,y);
                }
                if((i%2==0) && (j%2==0)){
                    h[++hcnt]=MP(x,y);
                }
            }
        }
        std::sort(l+1,l+lcnt+1);
        n=0;
        int j;
        for(int i=1;i<=lcnt;i=j){
            for(j=i;j<=lcnt&&l[i].first==l[j].first;j++);
            while(n>0&&l[n].second>=l[i].second) n--;
            l[++n]=l[i];
        }
        lcnt=n;
        std::sort(h+1,h+hcnt+1);
        n=0;
        for(int i=1;i<=hcnt;i=j){
            for(j=i;j<=hcnt && h[i].first==h[j].first;j++);
            if(!n || h[n].second<h[j-1].second){
                h[++n]=h[j-1];
            }
        }
        hcnt=n;
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int a=std::upper_bound(h+1,h+hcnt+1,MP(x,inf))-h;
            int b=std::upper_bound(l+1,l+lcnt+1,MP(x,-inf))-l;
//            std::cout<<" "<<a<<" "<<b<<std::endl;
            ans[i]='0'+(b<=lcnt&&h[a-1].second>=y&&l[b].second<=y);
        }
        ans[m]=0;
        puts(ans);
    }
    return 0;
}
/*
1
3 4
1 2 3
5 1
4 2
1 3
3 2
*/
