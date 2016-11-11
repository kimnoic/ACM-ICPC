#include <bits/stdc++.h>
using namespace std;
#define Max 300010
long long a[Max],s[Max];
map<long long ,int >mp;
int n;
int main(){
    cin>>n;
    int k=2;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    mp[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        mp[s[i]]++;
        k++;
    }
    int res=mp[0];
    //cout<<mp[0]<<endl;
    for(int i=n+1;i<=2*n;i++){
        k--;
        s[i]=s[i-1]+a[i];
        mp[s[i-n]]--;
        mp[s[i]]++;
        res=max(res,mp[s[i-n]]);
        //cout<<res<<endl;
    }
    if(k)
    cout<<n-res;
    return 0;
}
