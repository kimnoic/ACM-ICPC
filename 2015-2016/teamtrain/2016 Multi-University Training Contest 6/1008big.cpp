#include <bits/stdc++.h>
const int maxn=1e5+10;
int a[maxn],T;
int main(){
    std::cin>>T;
    while(T--){
        int n;
        std::cin>>n;
        int maxx=0;
        for(int i=1;i<=n;i++) {
            std::cin>>a[i];
            maxx=std::max(a[i],maxx);
        }
        long long sum=1e5 * 1e7;
        long long ans;
        int p;
        for(int i=0;i<2*maxx;i++){
            ans=0;
//            for(int j=1;j<=n;j++) std::cout<<(i^a[j]);
//            std::cout<<std::endl;
            for(int j=1;j<n;j++){
                ans+=(long long)abs((a[j+1]^i)-(a[j]^i));
            }
//            std::cout<<i<<" "<<ans<<std::endl;
            if(sum>ans){
                sum=ans;
                p=i;
            }
        }
        std::cout<<p<<" "<<sum<<std::endl;
    }
    return 0;
}
