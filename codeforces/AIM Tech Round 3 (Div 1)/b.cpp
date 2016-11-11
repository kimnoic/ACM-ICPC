#include <bits/stdc++.h>
const int maxn=1e5+10;
int x[maxn],n,a;
int main(){
    std::cin>>n>>a;
    for(int i=1;i<=n;i++) std::cin>>x[i];
    std::sort(x+1,x+n+1);
    int p=std::lower_bound(x+1,x+n+1,a)-x;
    //std::cout<<p;
    int d=1e9;
    if(n<=2){
        if(n==1){
            std::cout<<0;
        }
        else {
            std::cout<<std::min(abs(a-x[1]),abs(x[2]-a));
        }
        return 0;
    }
    if(p==1){
        d=std::min(x[n-1]-a,d);
    }
    else if(p==2){
        d=std::min(x[n]-a,2*(a-x[1])+x[n-1]-a);
    }
    else if(p>=n){
        if(a>=x[n])
        d=std::min(a-x[2],d);
        else {
            d=std::min(a-x[1],d);
            d=std::min(2*(x[n]-a)+a-x[2],d);
        }
    }
    else {
        d=std::min(2*(x[n-1]-a)+a-x[1],d);
        d=std::min(2*(x[n]-a)+a-x[2],d);
        d=std::min(2*(a-x[1])+x[n-1]-a,d);
        d=std::min(2*(a-x[2])+x[n]-a,d);
    }
    std::cout<<d;
    return 0;
}
