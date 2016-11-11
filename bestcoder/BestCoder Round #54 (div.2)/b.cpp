#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 14333
int prime[Max];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=Max;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=Max/i;j++){
        prime[prime[j]*i]=1;
        if(i%prime[j]==0) break;
        }
    }
}
int last[Max];
int cnt;
void cal(){
    getPrime();
    cnt=0;
    for(int i=2;i<=Max;i++){
        if(prime[i]){
            last[++cnt]=i;
        }
    }
}
int ans[233];
int top=0;
int main(){
    int T;
    cin>>T;
    cal();
    while(T--){
        int n;
        cin>>n;
        top=0;
        long long a;
        int k=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            k=0;
            for(int i=1;i<=cnt;i++){
                if(a%last[i]==0){
                    ans[++top]=last[i];
                    k++;
                    if(k>=2) break;
                    if(a%(last[i]*last[i])==0){
                        ans[++top]=last[i];
                        break;
                    }
                }
            }
        }
        sort(ans+1,ans+top+1);
        if(top<2) cout<<"-1"<<endl;
        else cout<<ans[1]*ans[2]<<endl;
    }
    //cout<<14333*14333<<endl;
    return 0;
}
