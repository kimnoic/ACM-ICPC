#include <bits/stdc++.h>
using namespace std;
#define Max 3000010
long long eul[Max];
void init(){
    memset(eul,0,sizeof(eul));
    eul[1]=1;
    /*
    for(int i=2;i<=Max;i++){
        if(!eul[i]){
            for(int j=i;j<Max;j+=i){
                if(!eul[j]) eul[j]=j;
                eul[j]=eul[j]/i*(i-1);
            }
        }
    }
    */
    for(int i=2;i<Max;i++)
        eul[i]=i;
    for(int i=2;i<Max;i++)
        if(eul[i]==i)
        for(int j=i;j<Max;j+=i)
        eul[j]=eul[j]/i*(i-1);
}
int main(){
    init();
    long long ans=0;
    int a,b;
    while(cin>>a>>b){
        ans=0;
        for(int i=a;i<=b;i++) ans+=eul[i];
        cout<<ans<<endl;
    }
    return 0;
}
