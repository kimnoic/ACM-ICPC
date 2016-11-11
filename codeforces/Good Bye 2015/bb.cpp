#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
#define Max 110
long long ttt[Max];
int main(){
    ttt[0]=1;
    for(int i=1;i<=62;i++){
        ttt[i]=(long long)ttt[i-1]*2;
    }
    cin>>m>>n;
    int i;
    for(i=0;i<=60;i++)
        for(int j=0;j<i-1;j++){
            if(ttt[i]-1-ttt[j]>=m && ttt[i]-1-ttt[j]<=n){
                ans++;
            }
        }
    if(i>60)
    cout<<ans<<endl;
    return 0;
}
