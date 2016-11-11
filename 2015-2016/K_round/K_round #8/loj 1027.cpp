#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int x[233];
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    int _case=0;
    cin>>T;
    while(T--){
        cin>>n;
        int cntp=0,cnto=0;
        int sump=0,sumo=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]>0) {
                cntp++;
                sump+=x[i];
            }
            else {
                sumo+=(-x[i]);
                cnto++;
            }
        }
        cout<<"Case "<<++_case<<": ";
        if(cntp==0){
            cout<<"inf"<<endl;
        }
        else {
            int sum=sump+sumo;
            int temp=gcd(sum,cntp);
            sum/=temp;
            cntp/=temp;
            cout<<sum<<"/"<<cntp<<endl;
        }
    }

    return 0;
}
