#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,cnt=0;
    n=2000000000;
    for(i=1,j=n/2-1;i<=n/4;i++,j--){
        if(i!=j&&2*i+2*j==n) cnt++;
    }
    cout<<cnt;
    return 0;
}
