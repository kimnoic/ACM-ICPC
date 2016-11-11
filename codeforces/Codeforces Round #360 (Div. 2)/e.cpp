#include <bits/stdc++.h>
using namespace std;
int n,k;
int f[550][550];
int v[550];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=v[i];j--){
            for(int kk=0;kk+v[i]<=k;kk++){
                if(f[j-v[i]][kk]) f[j][kk]=f[j][kk+v[i]]=1;
            }
        }
    }
    int sum=0;
    for(int i=0;i<=k;i++) if(f[k][i]) sum++;
    cout<<sum<<endl;
    for(int i=0;i<=k;i++) if(f[k][i]) cout<<i<<" ";
    return 0;
}
