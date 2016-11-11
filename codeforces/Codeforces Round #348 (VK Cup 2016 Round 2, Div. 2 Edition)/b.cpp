#include <bits/stdc++.h>
using namespace std;
#define Max 100100
char a[Max];
int b[Max];
int vis[Max];
int n;
int main(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int p=1;
    while(1){
        if(vis[p]){
           cout<<"INFINITE";
           return 0;
        }
        else {
            vis[p]=1;
            if(a[p]=='>'){
                p+=b[p];
            }
            else {
                p-=b[p];
            }
            if(p>n||p<1){
                cout<<"FINITE";
                return 0;
            }
        }
    }
    return 0;
}
