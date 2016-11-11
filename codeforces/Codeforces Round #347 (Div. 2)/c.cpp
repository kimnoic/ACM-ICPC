#include <bits/stdc++.h>
using namespace std;
map<int ,bool>mp;

int main(){
    int n;
    cin>>n;
    mp.clear();
    char t;
    for(int i=1;i<=n;i++){
        while(cin>>t&&t!='\'');
        int a;
        cin>>a;
        if(a<10){
            if(a==9){
                if(!mp[1989]){
                    cout<<1989<<endl;
                    mp[1989]=true;
                    continue;
                }
                else {
                    for(int j=0;;j++){
                        if(!mp[1990+j*10+a]){
                            mp[1990+j*10+a]=true;
                            cout<<1990+j*10+a<<endl;
                            break;
                        }
                    }
                }
            }
            else {
                for(int j=0;;j++){
                        if(!mp[1990+j*10+a]){
                            mp[1990+j*10+a]=true;
                            cout<<1990+j*10+a<<endl;
                            break;
                        }
                }
            }
        }
        else if(a<100){
            if(a>=89){
                if(!mp[1900+a]){
                    mp[1900+a]=true;
                    cout<<1900+a<<endl;
                    continue;
                }
                else {
                    for(int j=0;;j++){
                        if(!mp[2000+j*100+a]){
                            mp[2000+j*100+a]=true;
                            cout<<2000+j*100+a<<endl;
                            break;
                        }
                    }
                }
            }
            else {
                for(int j=0;;j++){
                        if(!mp[2000+j*100+a]){
                            mp[2000+j*100+a]=true;
                            cout<<2000+j*100+a<<endl;
                            break;
                        }
                    }
            }
        }
        else if(a<1000){
            if(a>=989){
                if(!mp[a+1000]){
                    mp[a+1000]=true;
                    cout<<a+1000;
                }
                else {
                    for(int j=1;;j++){
                        if(!mp[1000*j+a]){
                            mp[1000*j+a]=true;
                            cout<<1000*j+a<<endl;
                            break;
                        }
                    }
                }
            }
            else {
                for(int j=2;;j++){
                        if(!mp[1000*j+a]){
                            mp[1000*j+a]=true;
                            cout<<1000*j+a<<endl;
                            break;
                        }
                    }
            }
        }
        else if(a<10000){
            for(int j=0;;j++){
                        if(!mp[10000*j+a]){
                            mp[10000*j+a]=true;
                            cout<<10000*j+a<<endl;
                            break;
                        }
                    }
        }
        else {
            for(int j=0;;j++){
                        if(!mp[100000*j+a]){
                            mp[100000*j+a]=true;
                            cout<<100000*j+a<<endl;
                            break;
                        }
                    }
        }
    }
    return 0;
}
