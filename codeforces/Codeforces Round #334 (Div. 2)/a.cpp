#include <bits/stdc++.h>
using namespace std;
double m[5],w[5];
double k[5]={500,1000,1500,2000,2500};
double cal(int i){
    return max(0.3*k[i],(1-m[i]/250)*k[i]-50*w[i]);
}
int main(){
    for(int i=0;i<5;i++){
        cin>>m[i];
    }
    for(int i=0;i<5;i++){
        cin>>w[i];
    }
    double res=0;
    for(int i=0;i<5;i++){
        res+=cal(i);
    }
    int a,b;
    cin>>a>>b;
    res+=100*a;
    res-=50*b;
    cout<<round(res);
    return 0;
}
