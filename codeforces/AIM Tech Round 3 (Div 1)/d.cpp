#include <bits/stdc++.h>
int a00,a01,a10,a11,a0,a1;
const int maxn=1e6+10;
int ans[maxn];
int main(){
    std::cin>>a00>>a01>>a10>>a11;
    if(a00==0&&(a01||a10)) a0=1;
    else if(a00==0) a0=0;
    else {
        a0=sqrt(a00*2);
        while(a0*a0<=a00*2){
            if(a0*(a0+1)==a00*2){
                break;
            }
            a0++;
        }
        if(a0*(a0+1)!=a00*2){
        std::cout<<"Impossible";
        return 0;
        }
        a0++;
    }

    if(a11==0&&(a01||a10)) a1=1;
    else if(a11==0) a1=0;
    else {
        a1=sqrt(a11*2);
        while(a1*a1<=a11*2){
            if(a1*(a1+1)==a11*2){
                break;
            }
            a1++;
        }
        if(a1*(a1+1)!=a11*2){
        std::cout<<"Impossible";
        return 0;
        }
        a1++;
    }

    int n=a1+a0;
    if(n==0){
        std::cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a01>=a1){
            ans[i]=0;
            a01-=a1;
            a0--;
            continue;
        }
        if(a10>=a0){
            ans[i]=1;
            a10-=a0;
            a1--;
            continue;
        }
        std::cout<<"Impossible";
        return 0;
    }
    if(a0==0&&a1==0&&a01==0&&a10==0&&n>0)
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }
    else std::cout<<"Impossible";
    return 0;
}
