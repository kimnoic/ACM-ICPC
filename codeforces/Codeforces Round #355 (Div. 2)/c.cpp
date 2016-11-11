#include <bits/stdc++.h>
using namespace std;
int ff(char t){
    if(t>='0'&&t<='9') return t-'0';
    if(t>='A'&&t<='Z') return t-'A'+10;
    if(t>='a'&&t<='z') return t-'a'+36;
    if(t=='-') return 62;
    else return 63;
}
const int maxn = 1e5+10;
const int mod = 1e9+7;
char str[maxn];
int f[233];
void init(){
    for(int i=0;i<64;i++){
        int t=i;
        int num=0;
        int p=6;
        while(t){
            p--;
            if(t%2==0) num++;
            t/=2;
        }
        num+=p;
        f[i]=num;
    }
}
long long sum=0,ans;
int main(){
    init();
    cin>>str;
    sum=0;
    for(int i=0;str[i];i++){
        int k=f[ff(str[i])];
        sum+=k;
    }
    ans=1;
    for(int i=1;i<=sum;i++){
        ans*=3;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
