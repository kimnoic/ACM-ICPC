#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 200010
int find(int x){
    int tmp=1,ans=0;
    while(x){
        ans+=x%10*tmp;
        x/=10;
        tmp*=2;
    }
    return ans;
}
int dp[20][Max], mx[20];
int dfs(int len,int p,bool flag){
    if(len<0){
        return p>=0;
    }
    if(p<0){
        return 0;
    }
    if(!flag&&dp[len][p]!=-1)
        return dp[len][p];
    int cnt=flag?mx[len]:9,ans=0;
    for (int i=0;i<=cnt;i++){
        ans+=dfs(len-1,p-i*(1<<len),flag&&i==cnt);
    }
    if (!flag) {
        dp[len][p]=ans;
    }
    return ans;
}

int cal(int a,int b){
    int len=0;
    while(b){
        mx[len++]=b%10;
        b/=10;
    }
    return dfs(len-1,find(a),1);
}
int T;
int main(){
    int _case=1;
    int a,b;cin>>T;
    memset(dp,0xff,sizeof(dp));
    while(T--){
        scanf(" %d %d",&a,&b);
        printf("Case #%d: ",_case++);
        int res=cal(a,b);
        printf("%d\n",res);
    }
    return 0;
}
