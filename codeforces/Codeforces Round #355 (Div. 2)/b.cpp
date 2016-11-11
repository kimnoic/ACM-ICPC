#include <bits/stdc++.h>
using namespace std;
int n,k,h;

int main(){
    cin>>n>>k>>h;
    int t,res=0,sum=0;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t+res>k){
            if(t>k){
                if(res)
                    sum++;
                continue;
            }
            else {
                sum++;
                res=0;
            }
        }
        res+=t;
        sum+=res/h;
        res%=h;
    }
    if(res) sum++;
    cout<<sum;
    return 0;
}
