#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=1234567;
    int b=123456;
    int c=1234;
    int n;
    cin>>n;
    for(int i=0;i*a<=n;i++){
        int sum=n-i*a;
        for(int j=0;j*b<=sum;j++){
            int k=sum-j*b;
            if(k%c==0){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
