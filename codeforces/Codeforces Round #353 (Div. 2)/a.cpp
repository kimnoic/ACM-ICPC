#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
    cin>>a>>b>>c;
    if(c==0){
        if(a==b) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if(a==b){
        cout<<"YES";
        return 0;
    }
    if((b-a)%c==0&&((c>0&&(a<b))||(c<0)&&(a>b))) cout<<"YES";
    else cout<<"NO";
    return 0;
}
