#include <bits/stdc++.h>
using namespace std;
int T;
int x,c,k;
#define Max 2333
long long m;
int _case;
int main(){
    _case=0;
    cin>>T;
    while(T--){
        cout<<"Case #"<<++_case<<":"<<endl;
        cin>>x>>m>>c>>k;
        int kk=100000;
        long long num=0;
        long long res=0;
        int left=0;
        num=m/kk;
        left=m%kk;
        long long ans=0;
        if(!num){
            res=0;
            for(int i=1;i<=left;i++){
                ans*=10;
                ans+=x;
                ans%=c;
            }
            //cout<<ans<<endl;
            if(ans==k){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
            continue;
        }
        res=0;
        for(int i=1;i<=kk;i++){
            res*=10;
            res+=x;
            res%=c;
        }
        int y=111111;
        for(int i=2;i<=num;i++){
            res*=k;
            res+=y*x;
            res%=c;
        }
        for(int i=1;i<=left;i++){
            res*=10;
            res+=x;
            res%=c;
        }

        if(res==k){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;

    }
    return 0;
}
