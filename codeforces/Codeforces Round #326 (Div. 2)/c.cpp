#include <bits/stdc++.h>
using namespace std;
#define Max 1000010
int a[Max],n,t;
int res=0;
int main(){
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        a[t]++;
    }
    for(int i=0;i<=1000000;i++){
        if(a[i]>1){
            a[i+1]+=a[i]/2;
            res+=a[i]%2;
        }
        else res+=a[i];
    }
    cout<<res;
    return 0;
}
