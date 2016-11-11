#include <bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    cin>>n>>t;
    int k=1;
    for(int i=1;i<n;i++){
        k*=10;
        k%=t;
    }
    if(n==1&&t!=10) cout<<t<<endl;
    else if(n==1&&t==10) cout<<"-1";
    else if(k==0&&t==10){
        cout<<"1";
        for(int i=1;i<n;i++) cout<<"0";
    }
    else {
        cout<<"1";
        for(int i=1;i<n-1;i++) cout<<"0";
        cout<<t-k;
    }
    return 0;
}
