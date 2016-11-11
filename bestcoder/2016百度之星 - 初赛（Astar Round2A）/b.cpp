#include <bits/stdc++.h>
using namespace std;
#define Max 20
#define N 90000
int dp[Max][N];
int n;
int a[Max],p[Max];
int z[Max];
int main(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>p[i];
        if(p[i]==-1) cnt++;
    }
    for(int i=1;i<=n;i++){
        for(int k=0;k<(1<<n);k++){
            int st=1;
            memset(z,0,sizeof(z));
            int res=0;
            while(k){
                z[st]=k%2;
                if(z[st]) res++;
                k/=2;
            }
            if(res!=i-1) continue;
            int flag=0;
            if(z[i]==0){
                for(int j=1;j<=n;j++){
                    if(p[j]){
                        if(!z[j]){
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag) continue;
            if(p[i-1]){
                dp[i][k]=max(dp[i][k-1],dp[i][])
            }

        }
    }
    return 0;
}
