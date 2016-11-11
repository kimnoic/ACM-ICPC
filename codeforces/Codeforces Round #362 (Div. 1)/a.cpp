#include <bits/stdc++.h>
using namespace std;
int s,t,x;
int main(){
    cin>>s>>t>>x;
    x-=s;
    if(x==0){
        cout<<"YES";
        return 0;
    }
    int f=x/t;
    if(f<=0){
        cout<<"NO";
        return 0;
    }
    if(x%t==0||x%t==1){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}
