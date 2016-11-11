#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    int suma=a+b+c;
    suma=min(suma,2*a+2*b);
    suma=min(suma,2*a+2*c);
    suma=min(suma,2*b+2*c);
    cout<<suma;
    //cout<<"asdf";
    return 0;
}
