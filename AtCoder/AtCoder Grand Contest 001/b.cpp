#include<bits/stdc++.h>
using namespace std;
long long x,y;

long long n,t;

long long ans=0;
long long tt;
int main(){
    cin>>n>>t;
    ans+=t;
    ans+=n-t;
    x=t;
    y=n-t;
    while(x!=y){
        if(x<y){
            tt=(y-1)/x;
            y-=x*tt;
            ans+=2*x*tt;

        }
        else{
            tt=(x-1)/y;
            x-=y*tt;
            ans+=2*y*tt;

        }
    }
    ans+=x;
    cout<<ans<<endl;
    return 0;
}
