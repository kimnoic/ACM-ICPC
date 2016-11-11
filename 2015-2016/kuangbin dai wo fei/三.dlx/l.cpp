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
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_cxx;
int T;

int main(){
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        long long sum=0;
        long long t;
        for(int i=1;i<=n;i++){
            scanf("%lld",&t);
            sum^=t;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
