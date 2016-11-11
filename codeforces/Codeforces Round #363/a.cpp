#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
char t[maxn];
int aa[maxn];
int main(){
    int n;
    cin>>n;
    cin>>t;
    for(int i=0;i<n;i++) cin>>aa[i];
    long long ans=10000000000;
    for(int i=0;i<n;i++){
        if(t[i]=='R'&&t[i+1]=='L'){
            ans=min((long long)(aa[i+1]-aa[i])/2,ans);
        }
    }
    if(ans==10000000000) cout<<-1;else
    cout<<ans;
    return 0;
}
