#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    while(cin>>n&&n){
        double a=(-1+(sqrt(1+4*n)))/2;
        int t=(1+(sqrt(1+4*n)))/2;
        printf("%.2lf %d\n",a,t);
    }
    return 0;
}
