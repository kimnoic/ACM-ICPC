#include <bits/stdc++.h>
using namespace std;
#define Max 100010
int n,m;
int a[Max];
int res[Max];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=1,ct=0;
    int sum=0;
    for(int i=1;i<=1e9;i++){
        if(i==a[cnt]){
            cnt++;
        }
        else {
            sum+=i;
            if(sum>m) break;
            res[++ct]=i;
        }
    }
    cout<<ct<<endl;
    for(int i=1;i<=ct;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
