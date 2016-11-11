#include <bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,z;
long long sum1=0,sum2=0;
int main(){
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    if(a>x){
        sum1+=(a-x)/2;
    }
    else sum2+=(x-a);
    if(b>y){
        sum1+=(b-y)/2;
    }
    else sum2+=(y-b);
    if(c>z){
        sum1+=(c-z)/2;
    }
    else sum2+=(z-c);
    if(sum1>=sum2){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}

