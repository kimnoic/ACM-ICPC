#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int cal(int p,int cnt){
    if(cnt==0) return 1;
    return (long long)p*cal(p,cnt-1)%MOD;
}

int main(){
    int p,k;
    cin>>p>>k;
    if(k==0){
        cout<<cal(p,p-1);
    }
    else if(k==1){
        cout<<cal(p,p);
    }
    else {
        int m=1;
        int w=k;
        for(;w!=1;m++){
            w=(long long)w*k%p;
        }
        cout<<cal(p,(p-1)/m);
    }
    return 0;
}
