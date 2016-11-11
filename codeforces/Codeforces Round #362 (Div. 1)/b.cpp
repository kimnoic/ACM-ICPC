#include <bits/stdc++.h>
using namespace std;
char st[23333];
int main(){
    cin>>st;
    int f=0,p;
    for(int i=0;i<strlen(st);i++){
        if(st[i]=='e'){
            f=1;
            p=i;
            break;
        }
    }
    int sum=0;
    for(int i=p+1;i<strlen(st);i++){
        sum*=10;
        sum+=st[i]-'0';
    }
    f=0;
    int k=0;
    if(sum==0) k=1;
    int ff=0;
        int kk=0,pp,sm=0;
        for(int i=0;i<p;i++){
            if(st[i]=='.'){
                kk=1;
            }
            else if(kk){
                sm*=10;
                sm+=st[i]-'0';
            }
        }
        if(sm==0){
            ff=1;
        }
    //cout<<sum;
    for(int i=0;i<p;i++){
        if(st[i]=='.'){
            f=1;
            if(ff==1){
                break;
            }
            if(k){
                cout<<".";
                k=0;
            }
            continue;
        }
        else {
            cout<<st[i];
        }
        if(f){
            sum--;
            if(sum==0&&i!=p-1){
                cout<<".";
            }

        }
    }
    while(sum>0){
        cout<<"0";
        sum--;
    }
    return 0;
}
