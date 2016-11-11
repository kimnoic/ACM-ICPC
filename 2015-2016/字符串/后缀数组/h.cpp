#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <time.h>

using namespace std;
int n,m,k;
int T;


char a[10]="AABAABB";
char b[10]="aABAA";
char c[10]="aABC";
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        cin>>n>>m>>k;
        cout<<"Case #"<<++_case<<":"<<endl;
        if(m>n){
            cout<<"Impossible"<<endl;
        }
        else if(m==n){
            for(int i=1;i<=n;i++){
                    cout<<"A";
            }
            cout<<endl;
        }
        else if(k==1){
            cout<<"Impossible"<<endl;
        }
        else if(k==2){
            if(m==7&&n==8){
                cout<<"AABABBAA"<<endl;
                continue;
            }
            if(m<8){
                cout<<"Impossible"<<endl;
                continue;
            }
            for(int i=1;i<=m-8;i++){
                cout<<"A";
            }
            for(int i=m-7;i<=n;i++){
                cout<<a[(i-(m-7))%6+1];
            }
            cout<<endl;
        }
        else {
            if(m<3){
                cout<<"Impossible"<<endl;
                continue;
            }
            for(int i=1;i<=m-3;i++){
                cout<<"A";
            }
            for(int i=m-2;i<=n;i++){
                cout<<c[(i-(m-2))%3+1];
            }
            cout<<endl;
        }
    }
    return 0;
}
