#include <bits/stdc++.h>
using namespace std;
const int maxn = 1233;
int dp[maxn][maxn],dp2[maxn][maxn];
char a[maxn],b[maxn],c[maxn];
int T,lena,lenb,lenc;int cnt1,cnt2,ans;
struct pt{
    int st,en;
}p1[maxn],p2[maxn];

void init(){
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    memset(p1,0,sizeof(p1));
    memset(p2,0,sizeof(p2));
    lena=strlen(a+1);
    lenb=strlen(b+1);
    lenc=strlen(c+1);
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    for(int i=lena;i>=1;i--){
        for(int j=lenb;j>=1;j--){
            if(a[i]==b[j]){
                dp2[i][j]=dp2[i+1][j+1]+1;
            }
            else dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1]);
        }
    }
    cnt1=0;
    cnt2=0;
}

void solve(){
    for(int i=1;i<=lena;i++){
        if(a[i]==c[1]){
            int pos=1;
            int k=i,j;
            for(k=i+1,j=2;k<=lena;k++){
                if(a[k]==c[j]){
                    j++;
                }
                if(j==lenc+1){
                    break;
                }
            }
            if(j==lenc+1){
                p1[++cnt1].st=i;
                p1[cnt1].en=k;
            }
            else break;
        }
    }
    for(int i=1;i<=lenb;i++){
        if(b[i]==c[1]){
            int pos=1;
            int k=i,j;
            for(k=i+1,j=2;k<=lenb;k++){
                if(b[k]==c[j]){
                    j++;
                }
                if(j==lenc+1){
                    break;
                }
            }
            if(j==lenc+1){
                p2[++cnt2].st=i;
                p2[cnt2].en=k;
            }
            else break;
        }
    }
}
void print(){
    ans=0;
    for(int i=1;i<=cnt1;i++){
        for(int j=1;j<=cnt2;j++){
            int temp=dp[p1[i].st-1][p2[j].st-1]+lenc+dp2[p1[i].en+1][p2[j].en+1];
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        scanf("%s%s%s",a+1,b+1,c+1);
        init();
        solve();
        cout<<"Case #"<<++_case<<": ";
        print();
    }
    return 0;
}
