#include <bits/stdc++.h>
using namespace std;
int euler(int n){
    int res=n,a=n;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            res=res/i*(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
#define Max 33000
int eul[Max];
void init(){
    eul[1]=1;
    for(int i=2;i<Max;i++)
        eul[i]=i;
    for(int i=2;i<Max;i++)
        if(eul[i]==i)
        for(int j=i;j<Max;j+=i)
        eul[j]=eul[j]/i*(i-1);
}
int main(){
    int T;
    cin>>T;
    init();
    while(T--){
        int n;
        cin>>n;
        cout<<eul[n]<<endl;
    }
    return 0;
}
