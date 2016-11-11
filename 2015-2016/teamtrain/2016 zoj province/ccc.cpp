#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define Max 100010
int T, n, m;
long long a[Max],f[Max],c[Max];
int main() {
    cin>>T;
    while(T--){
        cin>>n;
        c[0]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i]=0;
            c[i]=(c[i-1]<<1)%MOD;
        }
        long long ans=0,sum=0;
        for(int i=1;i<=n;i++){
            (ans+=c[n-i]*(sum-f[a[i]]+MOD))%=MOD;
            (f[a[i]]+=c[max(1,i-1)])%=MOD;
            (sum+=c[max(1,i-1)])%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
