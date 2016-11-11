#include<bits/stdc++.h>
using namespace std;
#define Max 600*600
int s[Max];
void cal(int k,int len){
    if(len==0){
        if(k!=0)
            s[0]=0;
        else
            s[0]=1;
        return;
    }
    cal(k/2,len-1);
    int www=k%2;
    www^=1;
    int m=(1<<(len-1));
    for(int i=m;i<2*m;i++)
        s[i]=www^s[i-m];
}
int n;
void solve(){
    cin>>n;
    int cnt=0;
    for(int i=0;i<(1<<n);i++){
        cal(i,n);
        for(int j=0;j<(1<<n);j++)
            if(s[j])
                cout<<"+";
            else
                cout<<"*";
        if(i==cnt) cout<<endl;
        cnt++;
    }
    return ;
}

int main(){
    solve();
    return 0;
}
