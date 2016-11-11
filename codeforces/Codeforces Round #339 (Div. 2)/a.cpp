#include <bits/stdc++.h>
using namespace std;
long long l,r,k,tmp;
int main(){
    cin>>l>>r>>k;
    tmp=1;
    int flag=0;
    while(1){
        if(tmp>=l&&tmp<=r){
            cout<<tmp<<" ";
            flag=1;
        }

        if(tmp>(r/k)) break;
        tmp*=k;
    }
    if(!flag) cout<<-1;
    return 0;
}
