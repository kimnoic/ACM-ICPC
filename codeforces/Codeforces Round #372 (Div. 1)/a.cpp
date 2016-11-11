#include <bits/stdc++.h>
#define LL long long
int main(){
    LL cnt,n;
    std::cin>>n;
    cnt=1;
    while(cnt<=n){
        if(cnt==1) std::cout<<2<<std::endl;
        else std::cout<<(cnt+1)*(cnt+1)*cnt-cnt+1<<std::endl;
        cnt++;
    }
    return 0;
}

