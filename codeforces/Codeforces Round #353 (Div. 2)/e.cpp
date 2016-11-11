#include <bits/stdc++.h>
using namespace std;
#define Max 100010
int n,a[Max];
int l[Max<<2],r[Max<<2];
pair<int,int>mx[Max<<2];
long long sum,dp[Max];
void build(int rt,int x,int y){
    l[rt]=x;r[rt]=y;
    if(l[rt]==r[rt]){
        mx[rt]=make_pair(a[x],x);
        return ;
    }
    int mid=(x+y)>>1;
    build(rt*2,x,mid);
    build(rt*2+1,mid+1,y);
    mx[rt]=max(mx[rt*2],mx[rt*2+1]);
}
pair<int ,int>query(int rt,int x,int y){
    if(l[rt]==x&&r[rt]==y){
        return mx[rt];
    }
    int mid=l[rt]+r[rt]>>1;
    if(y<=mid) return query(rt<<1,x,y);
    else if(x>mid) return query(rt<<1|1,x,y);
    else return max(query(rt<<1,x,mid),query(rt<<1|1,mid+1,y));
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=n-1;i>0;i--){
        pair<int ,int>ans=query(1,i+1,a[i]);
        int m=ans.second;
        dp[i]=dp[m]-a[i]+m+n-i;
        sum+=dp[i];
    }
    cout<<sum;
    return 0;
}
