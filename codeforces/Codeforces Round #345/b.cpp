#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+7;
int n,a,b,T;
string s;
int d[maxn],d2[maxn];
int check(char k){
    if(k=='w')return 0;
    else return 1;
}
int update(int x,int y){
    if(x+y>1e9)return 1e9+1;
    return x+y;
}
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&T);
    T+=a;
    cin>>s;
    int now = 1;
    for(int i=0;i<n;i++){
        if(i!=0)d[i]=d[i-1];
        if(check(s[i])!=now)
            d[i]=update(d[i],a+b+1);
        else
            d[i]=update(d[i],a+1);
    }
    now = 1;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(i!=0)d2[i]=d2[i-1];
        if(check(s[i])!=now)
            d2[i]=update(d2[i],a+b+1);
        else
            d2[i]=update(d2[i],a+1);
    }
    reverse(s.begin(),s.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        if(T<d[i])break;
        int las = T - d[i];
        ans=max(i+1,ans);
        if(i==n-1)continue;
        if(las<a*i+d2[0])continue;
        las-=a*i;
        int l=0,r=n-i-2,Ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(d2[mid]<=las)l=mid+1,Ans=mid;
            else r=mid-1;
        }
        ans=max(i+1+Ans+1,ans);
    }
    if(s[n-1]!=s[0])T-=b;
    for(int i=0;i<n-1;i++){
        if(T<d2[i]+d[0]+a)break;
        int las = T - d2[i] - d[0] - a;
        ans=max(i+2,ans);
        if(las<a*i)continue;
        las-=a*i;
        las+=d[0];
        int l=0,r=n-i-2,Ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(d[mid]<=las)l=mid+1,Ans=mid;
            else r=mid-1;
        }
        ans=max(i+1+Ans+1,ans);
    }
    cout<<ans<<endl;
}
