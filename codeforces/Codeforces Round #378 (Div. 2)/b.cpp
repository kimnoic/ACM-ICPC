#include <bits/stdc++.h>
const int maxn=233333;
int a[maxn],b[maxn];
int suma,sumb;
int solve(int aa,int bb,int cc,int dd){
    aa-=cc,bb-=dd,aa+=dd,bb+=cc;
    return std::abs(aa-bb);
}
int main(){
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i]>>b[i],suma+=a[i],sumb+=b[i];
    int ans=std::abs(suma-sumb);
    int p=0;
    for(int i=1;i<=n;i++){
        if(solve(suma,sumb,a[i],b[i])>ans){
            p=i;
            ans=solve(suma,sumb,a[i],b[i]);
        }
    }
    std::cout<<p;
    return 0;
}
