#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    int ans=0,temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(temp-ans>15) {
            ans+=15;
            if(ans>90){
                cout<<90;
                return 0;
            }
            cout<<ans;
            return 0;
        }
        else ans=temp;
    }
    ans+=15;
    if(ans>90) cout<<90;
    else cout<<ans;
    return 0;
}
