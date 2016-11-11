#include <bits/stdc++.h>
const int maxn=1e5+10;
long long n,l,a[maxn];
int main(){
    std::cin>>n>>l;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    int temp=0;
    for(int i=2;i<=n;i++){
        if(a[i]+a[i-1]>=l){
            temp=i-1;
            break;
        }
    }
    if(temp){
        std::cout<<"Possible"<<std::endl;
        for(int i=1;i<temp;i++){
            std::cout<<i<<std::endl;
        }
        for(int i=n-1;i>temp;i--){
            std::cout<<i<<std::endl;
        }
        std::cout<<temp;
    }
    else {
        std::cout<<"Impossible";
    }
    return 0;
}
