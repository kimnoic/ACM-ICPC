#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int k=0;
int head[23333],hs[233333];
char a[233];
int x,y;
int main(){
    int n,m;
    cin>>n>>m;
    k=0;
    for(int i=1;i<=n;i++){
        int y;
        cin>>y;
        y+=10000;
        head[++k]=y;
        int temp=k;
        while(temp>1){
            if(head[temp]<head[temp/2]){
                swap(head[temp],head[temp/2]);
                temp/=2;
            }
            else break;
        }
    }

    for(int i=1;i<=n;i++){
        hs[head[i]]=i;
    }
    while(m--){
        cin>>x;
        cin>>a;
        x+=10000;
        if(a[0]=='a'){
            cin>>y;
            y+=10000;
            cin>>a;
            cin>>a;
            if(head[hs[x]/2]==head[hs[y]/2]){
                cout<<"T"<<endl;
            }
            else cout<<"F"<<endl;
            continue;
        }
        cin>>a;
        if(a[0]=='a'){
            cin>>a;
            cin>>a;
            cin>>y;
            y+=10000;
            if(head[hs[x]/2]==y){
                cout<<"T"<<endl;
            }
            else cout<<"F"<<endl;
            continue;
        }
        cin>>a;
        if(a[0]=='r'){
            if(head[1]==x){
                cout<<"T"<<endl;
            }
            else cout<<"F"<<endl;
            continue;
        }
        cin>>a;
        cin>>y;

            y+=10000;
        if(x==head[hs[y]/2]){
            cout<<"T"<<endl;
        }
        else cout<<"F"<<endl;
    }
    return 0;
}
