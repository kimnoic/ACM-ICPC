#include <bits/stdc++.h>
int m,n;
int ff[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
std::string a,b;

int judge(std::string str){
    if(str=="monday")return 0;
    if(str=="tuesday")return 1;
    if(str=="wednesday")return 2;
    if(str=="thursday")return 3;
    if(str=="friday")return 4;
    if(str=="saturday")return 5;
    if(str=="sunday")return 6;
}

int main(){
    std::cin>>a>>b;
    int a1=judge(a),a2=judge(b);
    for(int i=1;i<=11;i++){
        if((ff[i]+a1)%7==a2){
            std::cout<<"YES";
            return 0;
        }
    }
    std::cout<<"NO";
    return 0;
}
