#include <bits/stdc++.h>
using namespace std;
#define Max 1443000

long long a[Max],b[Max];
long long sum[Max];
long long m;
long long cal(int x){
    long long l=x,r=m;
    long long mid=(l+r)/2;
    long long k=(long long)x*(x+1)/2;

    while(l<r){
        long long res=sum[x]+k*(mid-x);
        if(res>m){
            r=mid;
        }
        else if(res<m){
            l=mid+1;
        }
        else break;
        mid=(l+r)/2;
    }
    if(sum[x]+k*(mid-x)==m) return mid;
    else return 0;
}
int main(){
    cin>>m;
    int cnt=0;
    int i;long long k;
    for(i=1;i<=Max;i++){
        //cout<<i<<endl;
        sum[i]=(long long)sum[i-1]+(long long)(i)*(long long)(i);
        k=cal(i);
        if(k){
            a[++cnt]=i;
            b[cnt]=k;
        }
        if(k<=i) break;
    }
    if(i==k) {
        cout<<cnt*2-1<<endl;
        for(int i=1;i<=cnt;i++){
            printf("%I64d %I64d\n",a[i],b[i]);
        }
        for(int i=cnt-1;i>=1;i--){
            printf("%I64d %I64d\n",b[i],a[i]);
        }
        return 0;
    }
    cout<<cnt*2<<endl;
    for(int i=1;i<=cnt;i++){
        printf("%I64d %I64d\n",a[i],b[i]);
    }
    for(int i=cnt;i>=1;i--){
        printf("%I64d %I64d\n",b[i],a[i]);
    }
    return 0;
}
