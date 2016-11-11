#include <bits/stdc++.h>
using namespace std;
int a[100010];
int cnt=0;
int main(){
    int n,m;
    cin>>n;
    while(n){
        m=n;
        cnt++;
        int k=0;
        while(m){
            k++;
            m/=2;
        }
        printf("%d ",k);
        k--;
        n-=(1<<k);
    }
    return 0;
}
