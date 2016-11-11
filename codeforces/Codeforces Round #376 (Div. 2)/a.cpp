#include <bits/stdc++.h>
const int maxn=233;
char t[maxn];
int main(){
    std::cin>>t;
    int len=std::strlen(t);
    char temp='a';
    int ans=0;
    for(int i=0;i<len;i++){
        if(t[i]>=temp) ans+=std::min(t[i]-temp,temp+26-t[i]);
        else ans+=std::min(temp-t[i],t[i]+26-temp);
        temp=t[i];
    }
    std::cout<<ans;
    return 0;
}
