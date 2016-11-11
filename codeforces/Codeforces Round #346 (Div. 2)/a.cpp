#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
    cin>>n>>a>>b;
    int sum=abs((abs(a+b))%n);
    if(sum==0) sum=n;
    cout<<sum;
    return 0;
}
