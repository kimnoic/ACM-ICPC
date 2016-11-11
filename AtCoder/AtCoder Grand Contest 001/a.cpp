#include <bits/stdc++.h>
using namespace std;
int n;
int a[233];
int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    sort(a+1,a+2*n+1);
    int sum=0;
    for(int i=1;i<=2*n;i++){
        if(i%2)
            sum+=a[i];
    }
    cout<<sum;
    return 0;
}
