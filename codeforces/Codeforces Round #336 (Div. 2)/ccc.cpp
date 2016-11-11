#include<bits/stdc++.h>
using namespace std;
const int lim=1e6+10;
int ha[lim];
struct self
{
    int pos,w;
}s[lim];
int f[lim];
int dp[lim];
int m,ans;
int cmp(self a,self b)
{
    return a.pos<b.pos;
}
int maxpos;

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&s[i].pos,&s[i].w);
    sort(s+1,s+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        ha[s[i].pos]=i;
    }
    maxpos=s[m].pos;
    int last=0;
    for(int i=0;i<=maxpos;i++)
        if(ha[i]==0)
            if(i!=0)
                ha[i]=ha[i-1];
    dp[0]=0;
    dp[1]=1;
    //for(int i=0;i<=maxpos;i++)cout<<ha[i]<<endl;
    for(int i=2;i<=m;i++)
    {
        int newpos=s[i].pos-s[i].w-1;
        int dy=ha[newpos];
        dp[i]=dp[dy]+1;
        //cout<<s[i].pos<<" "<<s[i].w<<endl;
        //cout<<"dy="<<dy<<endl;
        //cout<<"dp["<<i<<"]="<<dp[i]<<endl;
    }
    ans=m;
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,m-dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
