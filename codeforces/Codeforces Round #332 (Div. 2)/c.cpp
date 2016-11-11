#include <bits/stdc++.h>
using namespace std;
#define Max 100010
int a[Max],b[Max];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int ans=0,max=0;
    long long suma=0,sumb=0;
    for(int i=1;i<=n;i++){
        suma+=a[i];
        sumb+=b[i];
        if(a[i]>max)
            max=a[i];
        if(b[i]==max&&suma==sumb)
            ans++;
    }
    cout<<ans;
    return 0;
}
