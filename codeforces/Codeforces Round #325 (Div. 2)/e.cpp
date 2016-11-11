#include <bits/stdc++.h>
using namespace std;

bool solve(long long a,long long b){
    if(a==b){
        if(a==1&&b==1){
            return true;
        }
        else {
            cout<<"Impossible";
            return false;
        }
    }
    else if(a==1||b==1) return true;
    else if(a>b){
        long long k=a%b;
        if(k==0&&b!=1){
            cout<<"Impossible";
            return false;
        }
        else {
            a=a%b;
            solve(a,b);
        }
    }
    else {
        long long k=b%a;
        if(k==0&&a!=1){
            cout<<"Impossible";
            return false;
        }
        else {
            b=b%a;
            solve(a,b);
        }
    }
}
void cal(long long a,long long b){
    if(a==1&&b==1) return ;
    else if(a>b){
        long long k=a/b;
        if(b==1)
        {cout<<k-1<<"A";
        return ;}
        cout<<k<<"A";
        cal(a%b,b);
    }
    else {
        long long k=b/a;
        if(a==1){
            cout<<k-1<<"B";
            return ;
        }

        cout<<k<<"B";
        cal(a,b%a);
    }
}
int main(){
    long long a,b;
    cin>>a>>b;
    if(solve(a,b)){
        //cout<<"asdf";
        cal(a,b);
    }
    return 0;
}
