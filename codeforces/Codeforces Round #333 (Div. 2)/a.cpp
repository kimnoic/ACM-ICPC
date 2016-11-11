#include <bits/stdc++.h>
using namespace std;
long long a,b;

int main(){
    int x,y;
    cin>>x>>y;
    a=0;b=0;
    int t;
    for(int i=1;i<=x;i++){
        a*=y;
        cin>>t;
        a+=t;
    }
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        b*=y;
        cin>>t;
        b+=t;
    }
    if(a==b) cout<<'=';
    else if(a>b) cout<<'>';
    else cout<<'<';
    return 0;
}
