#include <bits/stdc++.h>
const int maxn=233333;
int a[maxn],n;
int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]%=2;
        if(a[i]) {
            if(a[i+1]) a[i+1]--;
            else {
                std::cout<<"NO";
                return 0;
            }
        }
    }
    std::cout<<"YES";
    return 0;
}
