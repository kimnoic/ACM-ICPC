#include <bits/stdc++.h>
const int maxn = 1e5+10;
int a[maxn];int n,d,b;
int main(){
    std::cin>>n>>b>>d;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int sum=0,tol=0;
    for(int i=1;i<=n;i++){
        if(a[i]>b) continue;
        sum+=a[i];
        if(sum>d){
            tol++;
            sum=0;
        }
    }
    std::cout<<tol;
    return 0;
}
