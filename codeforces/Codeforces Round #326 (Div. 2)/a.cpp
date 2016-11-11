#include <bits/stdc++.h>
using namespace std;
int n;
int res=0;
int a,p;
int minn;
int main(){
    minn=1000;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>p;
        if(p<minn) {
            minn=p;
        }
        res+=a*minn;
    }
    cout<<res;
    return 0;
}
