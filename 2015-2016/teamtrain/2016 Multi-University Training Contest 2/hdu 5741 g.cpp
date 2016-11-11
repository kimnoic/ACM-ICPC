#include <bits/stdc++.h>
const int maxn=1010;
const int maxm=1010*1010;
const int inf=2e9;
#define MP std::make_pair
std::pair<int,int>l[maxm],h[maxm];
int lcnt,m,hcnt,v[maxn],n;
char ans[maxm];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",v+i);
        }
        lcnt=0,hcnt=0;
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=i;j<n;j++){
                if(j&1){
                    y+=v[j];
                }
                else {
                    x+=v[j];
                }
                if((i%2==0) && (j%2==0)){
                    l[lcnt++]=MP(x,y);
                }
                if((i%2==1) && (j%2==1)){
                    h[hcnt++]=MP(x,y);
                }
            }
        }
        std::sort(l,l+lcnt);
        n=0;
        for(int i=0,j;i<lcnt;i=j){
            for(j=i;j<lcnt&&l[i].first==l[j].first;j++);
            while(n>0&&l[n-1].second>=l[i].second) n--;
            l[n++]=l[i];
            //std::cout<<n<<std::endl;
        }
        lcnt=n;
//        for(int i=0;i<lcnt;i++){
//            std::cout<<" l "<<l[i].first<<" "<<l[i].second<<std::endl;
//        }
        std::sort(h,h+hcnt);
        n=0;
        //std::cout<<hcnt<<std::endl;
        for(int i=0,j;i<hcnt;i=j){
            for(j=i;j<hcnt && h[i].first==h[j].first;j++);
            if(!n || h[n-1].second<h[j-1].second){
                h[n++]=h[j-1];
            }
        }
        //std::cout<<n<<std::endl;
//        for(int i=1;i<=n;i++){
//            printf(" h %d %d\n",h[i].first,h[i].second);
//            //cout>>l[i].first<<" "<<l[i].second<<endl;
//        }
        hcnt=n;
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int a=std::upper_bound(h,h+hcnt,MP(x,+inf))-h;
            int b=std::upper_bound(l,l+lcnt,MP(x,-inf))-l;
            //std::cout<<" "<<a<<" "<<b<<std::endl;
            ans[i]='0'+(b<lcnt&&h[a-1].second>=y&&l[b].second<=y);
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
