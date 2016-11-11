#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long dp[30][3];
int digit[233];
void init(){
    dp[0][0]=1;
    for(int i=1;i<=20;i++){
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1]+dp[i-1][2]*10;
    }
}
int q[23];
long long cal(long long n){
    memset(q,0,sizeof(q));
    int len=0;
    while(n){
        q[++len]=n%10;
        n/=10;
    }
    long long res=0;
    bool flag=false;
    int last=0;
    for(int i=len;i>=1;i--){
        res+=dp[i-1][2]*q[i];
        if(flag){
            res+=dp[i-1][0]*q[i];
        }
        if(!flag&&q[i]>4){
            res+=dp[i-1][1];
        }
        if(last==4&&q[i]==9) flag=true;
        last=q[i];
    }
    return res;
}
long long n;
int main(){
    init();
    int T,t;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<cal(n+1)<<endl;
    }
    return 0;
}
