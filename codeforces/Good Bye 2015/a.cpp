#include <bits/stdc++.h>
using namespace std;
int a;
char b[12];
char c[12];
int main(){
    cin>>a>>b>>c;
    if(c[0]=='m'){
        if(a<=29) cout<<12;
        else if(a==30) cout<<11;
        else cout<<7;
    }
    else {
        if(a==5||a==6) cout<<53;
        else cout<<52;
    }
    return 0;
}
