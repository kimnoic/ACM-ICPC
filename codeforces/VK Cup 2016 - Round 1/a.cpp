#include <bits/stdc++.h>
using namespace std;
#define Max 55
int p[Max],t[Max],n,c;
int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    int suma=0,sumb=0;
    int tim=0;
    int resa=0,resb=0;
    for(int i=1;i<=n;i++){
        tim+=t[i];
        suma+=(p[i]-c*tim);
        resa=max(resa,suma);
    }
    tim=0;
    for(int i=n;i>=1;i--){
        tim+=t[i];
        sumb+=(p[i]-c*tim);
        resb=max(sumb,resb);
    }
    if(resa>resb){
        cout<<"Limak";
    }
    else if(resa<resb) {
        cout<<"Radewoosh";
    }
    else cout<<"Tie";
    return 0;
}
