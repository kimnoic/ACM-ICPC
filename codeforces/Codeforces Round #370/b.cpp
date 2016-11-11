#include <bits/stdc++.h>
const int maxn=1e5+10;
char s[maxn];
int a,b;
void check(char t){
    if(t=='L') a++;
    else if(t=='R') a--;
    else if(t=='U') b++;
    else if(t=='D') b--;
}
int main(){
    std::cin>>s;
    int len=strlen(s);
    a=0,b=0;
    if(len%2){
        std::cout<<-1;
        return 0;
    }
    for(int i=0;i<len;i++){
        check(s[i]);
    }
    std::cout<<(abs(a)+abs(b))/2;
    return 0;
}
