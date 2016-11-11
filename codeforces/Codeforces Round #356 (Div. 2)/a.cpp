#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[233];
int main(){
    int n=5;
    int sum=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(!a[x]){
            cnt++;
            a[cnt]=x;
            b[x]++;
        }
        else {
            b[x]++;
        }
        sum+=x;
    }
    int k=0;
    for(int i=1;i<=cnt;i++){
        if(b[a[i]]>1){
            k=max(min(3,b[a[i]])*a[i],k);
        }
    }
    cout<<sum-k;
    return 0;
}
