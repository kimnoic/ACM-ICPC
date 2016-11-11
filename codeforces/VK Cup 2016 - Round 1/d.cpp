#include <bits/stdc++.h>
using namespace std;
#define Max 200010
long long a[Max],b[Max];
int k,n;
int main(){
    cin>>n>>k;
    int p1,l=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i+1]+=(a[i]/2);
        a[i]%=2;
    }
    int flag=n;
    for(int i=0;i<=n;i++){
        if(a[i]){
            flag=i;
            break;
        }
    }
    long long sum=0;
    int res=0;
    for(int i=n;i>=0;i--){
        sum=sum*2+a[i];
        if(abs(sum)>1ll*1e9*1e7)break;
        if(i<=flag){
            long long p = b[i]-sum;
            if(abs(p)<=k){
                if(i==n&&p==0)continue;
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}
