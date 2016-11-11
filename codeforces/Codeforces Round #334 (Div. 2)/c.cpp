#include <bits/stdc++.h>
using namespace std;
int flag_0,flag_1;
#define Max 100010
char a[Max];
int main(){
    int n;
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
        scanf(" %c",&a[i]);
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1])k++;
    }
    int cnt=0;
    for(int i=1;i<n;){
        int p=i;
        while(a[i]==a[p]){
            p++;
        }
        i=p;
        cnt++;
        if(i==n&&a[i]!=a[i-1]) cnt++;
    }
    if(k>=2) cnt+=2;
    else if(k==1) cnt+=1;
    cout<<cnt;
    return 0;
}
