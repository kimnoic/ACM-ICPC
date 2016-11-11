#include <bits/stdc++.h>
using namespace std;
int T;
const int maxn = 1010;
int val[maxn],v[maxn],f[maxn],n,vv;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>vv;
        for(int i=1;i<=n;i++) cin>>val[i];
        for(int i=1;i<=n;i++) cin>>v[i];
        memset(f,0,sizeof(f));
        int k=0;
        for(int i=1;i<=n;i++){
            for(int j=vv;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+val[i]);
            }
        }
        cout<<f[vv]<<endl;
    }
    return 0;
}
