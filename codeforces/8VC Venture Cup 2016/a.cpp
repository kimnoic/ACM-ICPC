#include <bits/stdc++.h>
using namespace std;
long long s,x,a,ans;

int main(){
    cin>>s>>x;
    a=(s-x)/2;
    ans=0;
    if(s==x) ans=-2;
    if(s>=x&&(s-x)%2==0){
        int cnt=0;
        int flag;
        while(x){
            flag=0;
            if(x&1){
                if(a&1) {
                    flag=1;
                }
                cnt++;
            }
            if(flag) break;
            x/=2;
            a/=2;
        }
        if(flag){
            cout<<0;
        }
        else cout<<ans+(1LL<<cnt);
    }
    else cout<<0;
    return 0;
}
