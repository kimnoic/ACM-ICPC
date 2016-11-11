#include <bits/stdc++.h>
using namespace std;
#define Max 500010
int t[Max];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    t[n+1]=t[n];
    int maxx=0;
    int flag=0;
    flag=0;
    for(int i=1;i<=n;i++){
        if(t[i]==t[i+1]) continue;
        for(int j=i+1;j<=n;j++){
            if(t[j]==t[j+1]||j==n){
                flag=j;
                break;
            }
        }
        if(t[i]==t[flag]){
            for(int j=i+1;j<flag;j++){
                t[j]=t[i];
            }
            maxx=max(maxx,(flag-i)/2);
        }
        else {
            maxx=max(maxx,(flag-i)/2);
            for(int j=i+1;j<=i+(flag-i)/2;j++){
                t[j]=t[i];
            }
            for(int j=i+(flag-i)/2+1;j<flag;j++){
                t[j]=t[flag];
            }
        }
        i=flag;
    }
    cout<<maxx<<endl;
    for(int i=1;i<=n;i++){
        cout<<t[i];
        if(i!=n) cout<<" ";
    }
    return 0;
}
