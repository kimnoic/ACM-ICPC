#include <bits/stdc++.h>
using namespace std;
#define Max 200010
long long sum[Max],w[Max],p[Max],psum[Max];
int n,m,k;
long long ans=0;int re=0,r=0;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>p[i];
        sum[i]=sum[i-1]+w[i];
        psum[i]=psum[i-1]+p[i];
    }
    for(int i=n;i>m;i--){
        long long wei=sum[i]-sum[i-m];
        long long res=sum[i-m]*k;
        int l=0,r=i-m;
        int mid=(l+r)/2;
        while(l<r){
                //cout<<l<<" "<<r<<endl;
            if(res-sum[mid]*k>wei){
                l=mid+1;
            }
            else {
                r=mid;
            }
            mid=(l+r)/2;
        }
        if(mid!=0)
        if(ans<=psum[mid-1]+psum[n]-psum[i]) {
            ans=psum[mid-1]+psum[n]-psum[i];
            re=mid-1;r=n-i;
        }
    }
    cout<<re+r<<" "<<ans;
    for(int i=1;i<r;i++) cout<<"H";
    for(int i=1;i<=re;i++) cout<<"T";
    return 0;
}
