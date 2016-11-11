#include <bits/stdc++.h>
long long a,b;
int main(){
    std::cin>>a>>b;
    if(a*b<=0){
        std::cout<<"Zero";
        return 0;
    }
    else if(a>0&&b>0){
        std::cout<<"Positive";
        return 0;
    }
    else {
        if((b-a)%2==0){
            std::cout<<"Negative";
        }
        else std::cout<<"Positive";
    }
    return 0;
}
