#include <bits/stdc++.h>
using namespace std;
int n;
int a,b;
char t[233];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        cin>>a>>b;
        if(a>=2400&&b>a){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
