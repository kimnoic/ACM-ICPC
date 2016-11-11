#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[maxn],b[maxn];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int temp=0;
    for(int i=1;i<=n;i++){
        if(a[i]>temp){
            temp++;
        }
        else {
            temp=a[i];
        }
    }
    cout<<temp+1;
    return 0;
}
