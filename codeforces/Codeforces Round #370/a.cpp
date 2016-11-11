#include <bits/stdc++.h>
const int maxn=1e5+10;
int a[maxn],b[maxn];
int n;
int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        std::cout<<a[i]+a[i+1]<<" ";
    }
    return 0;
}
