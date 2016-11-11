#include <bits/stdc++.h>
#define lson r,m,rt*2
#define rson m+1,l,rt*2+1
char mp[10][10];
using namespace std;
int maxx=10;
int main(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='W'){
                int flag=0;
                for(int k=i-1;k>=1;k--){
                    if(mp[k][j]!='.'){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    maxx=min(maxx,i);
                }
            }
        }
    }
    int minn=0;
    for(int i=8;i>=1;i--){
        for(int j=1;j<=8;j++){
            if(mp[i][j]=='B'){
                int flag=0;
                for(int k=i+1;k<=8;k++){
                    if(mp[k][j]!='.'){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    minn=max(minn,i);
                }
            }
        }
    }
    maxx=maxx-1;
    minn=8-minn;
    if(maxx<=minn){
        cout<<"A";
    }
    else cout<<"B";
    return 0;
}
/*
........
....W...
........
........
........
........
...B....
........
*/
