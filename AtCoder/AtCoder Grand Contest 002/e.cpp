#include <bits/stdc++.h>
const int maxn=1e5+10;
int a[maxn],n;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::sort(a+1,a+n+1,cmp);
    int p=1;
    for(int i=1;i<=n;i++,p=i){
        if(a[i]<i) {
            break;
        }
    }
    p--;int f=p;
    bool flag=0;
    for(int i=p;i<=n&&a[i]>=p;i++,f=i);
    if((f-p-1)&1) flag=1;
    if((a[p]-p)&1) flag=1;
    if(flag) std::cout<<"First";
    else std::cout<<"Second";
    return 0;
}
