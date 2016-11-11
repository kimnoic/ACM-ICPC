#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    if(n%3==0) cout<<n/3*2;
    else cout<<n/3*2+1;
    return 0;
}
