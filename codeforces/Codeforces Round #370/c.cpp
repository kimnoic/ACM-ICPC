#include <bits/stdc++.h>
const int maxn=10;
int a[maxn];
int x,y;
int main(){
    std::cin>>x>>y;
    for(int i=1;i<=3;i++) a[i]=y;
    std::sort(a+1,a+4);
    int cnt=0;
    while(1){
        if(a[1]==x) break;
        cnt++;
        a[1]=std::min(x,a[2]+a[3]-1);
        std::sort(a+1,a+4);
    }
    std::cout<<cnt;
    return 0;
}
