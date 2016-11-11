#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t>k) sum+=2;
        else sum++;
    }
    cout<<sum;
    return 0;
}
