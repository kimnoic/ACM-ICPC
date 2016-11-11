#include <bits/stdc++.h>
using namespace std;

#define Max 233
int n;
int a[Max];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i;
    for(i=1;i<=n;i++){
        if(a[i]==1){
            break;
        }
    }
    int res=0;
    int flag=0;
    for(int j=i;j<=n;j++){
        if(a[j]&&flag==2) {
            res++;
            flag=0;
        }
        else if(a[j]==1 && flag==1){
            flag=0;
            res+=2;
        }
        else if(a[j]==1){
            res++;
            flag=0;
        }
        else flag++;
    }
    cout<<res;
    return 0;
}
