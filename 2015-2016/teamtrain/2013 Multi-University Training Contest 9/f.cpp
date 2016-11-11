#include <bits/stdc++.h>
using namespace std;
const int maxn = 510010;
int t1[maxn],t2[maxn],c[maxn];
bool cmp(int *r,int a,int b,int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}
long long get(int n){
    long long i=0;
    if(n==0)i=1;
    while(n){
        i++;
        n/=10 ;
    }
    return i+1;
}
char str[maxn];int s[maxn];

int sa[maxn],rnk[maxn],height[maxn],l[maxn],r[maxn],dp[33][maxn],f[maxn];
long long d[maxn];
void build_sa(int s[],int n,int m){
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1){
        p=0;
        for(i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}
void getHeight(int s[],int n){
    int i,j,k=0;
    for(i=0;i<=n;i++)rnk[sa[i]]=i;
    for(i=0;i<n;i++){
        if(k)k--;
        j=sa[rnk[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rnk[i]]=k;
    }
}
void rmq(int n){
    int i,j;
    for(i=1;i<=n;i++) {dp[0][i]=height[i];}
    for(i=1;i<=20;i++){
        for(j=1;j+(1<<i)-1<=n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
            //if(dp[i][j]!=0)cout<<"dp "<<dp[i][j]<<endl;
        }
    }
}
int query(int l,int r){
    if(l>r) swap(l,r);
    l++;
    if(l==r) return dp[0][l];
    int k=r-l+1;
    return min(dp[f[k]][l],dp[f[k]][r-(1<<f[k])+1]);
}
long long ans1,ans2;
int n;
void solve(){
    int i,j,k;
    for(i=2;i<=n;i++){
        long long add;
        if(l[i]==l[i-1]) add=min(d[i],d[i-1]);
        else add=query(rnk[l[i-1]],rnk[l[i]]);
        add=min(add,min(d[i],d[i-1]));
//        cout<<"add "<<add<<endl;
        ans2+=get(add);
//        cout<<ans2<<endl;
        ans2+=(long long)d[i]-add+1;
//        cout<<"i "<<ans2<<endl;
    }
}
void init(){
    for(int i=1,j=0;i<maxn-1111;i++){
        if(i > 1 << j + 1) j++;
        f[i]=j;
    }
}


int main(){
    init();
    while(cin>>str){
        int len=strlen(str);
        cin>>n;
        ans1=0;
        ans2=0;
        for(int i=1;i<=n;i++){
            cin>>l[i]>>r[i];
            r[i]--;
            d[i]=r[i]-l[i]+1;
            ans1+=(long long)d[i]+1;
        }

        for(int i=0;i<len;i++) s[i]=str[i]; s[len]=0;
        build_sa(s,len+1,555);
        getHeight(s,len);
        //da(s,sa,rnk,height,len+1,555);
//        da ( s , len + 1 , 555 ) ;
//        cout<<len<<endl;
//        for(int i=0;i<len;i++) cout<<height[i]<<" ";cout<<endl;
        ans2=2+d[1]+1;
//        cout<<ans2<<endl;
        rmq(len);
        solve();
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
//0 0 3 2 2 1 0 2 1 1 2 1 0 4 0 0 0 0 1 0 5 0 4 3 3 1 0 1 2 0 1 0 1 0 3 0 1
/*
add 5
i 17
add 0
i 23
add 3
i 29
add 4
i 35
add 3
i 40
43 40
*/
