#include <bits/stdc++.h>
using namespace std;
long long t;
long long pre=0;
int cnt;
int res;
int main(){
    int n;
    cnt=0;
    res=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t>=pre){
            pre=t;
            cnt++;
            res=max(res,cnt);
        }
        else {
            pre=t;
            cnt=1;
        }
    }
    cout<<res;
    return 0;
}
