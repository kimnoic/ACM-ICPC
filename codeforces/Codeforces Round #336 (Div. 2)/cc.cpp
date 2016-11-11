#include<bits/stdc++.h>
using namespace std;
#define Max 1000010
int a[Max];
struct pt{
    int p,w;
}s[Max];
int f[Max],dp[Max],n,ans;
int cmp(pt a,pt b){
    return a.p<b.p;
}
int maxp;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i].p,&s[i].w);
    sort(s+1,s+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        a[s[i].p]=i;
        cnt++;
    }
    maxp=s[n].p;
    int last=0;
    for(int i=0;i<=maxp;i++)
        if(a[i]==0)
            if(i!=0)
                a[i]=a[i-1];
    dp[0]=0;
    dp[1]=1;
    ans=n;
    ans=min(ans,n-dp[1]);
    for(int i=2;i<=n;i++){
        int newpos=s[i].p-s[i].w-1;
        int y=a[newpos];
        dp[i]=dp[y]+1;
        ans=min(ans,n-dp[i]);
    }
    if(cnt==n)cout<<ans<<endl;
    return 0;
}
