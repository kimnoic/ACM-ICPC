#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define MOD 1000000007
#define Max 10001
long long dp[Max];

int main(){
    int T;
    cin>>T;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=10000;i++){
        dp[i]=((i-1)*(dp[i-1]+dp[i-2]))%MOD;
    }
    while(T--){
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
