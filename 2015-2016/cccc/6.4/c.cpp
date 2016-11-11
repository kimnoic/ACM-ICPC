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
int a,b;
int ansa,ansb;
int a1,a2,b1,b2;
int n;
int main(){
    cin>>a>>b;
    cin>>n;
    ansa=0;
    ansb=0;
    for(int i=1;i<=n;i++){
        cin>>a1>>a2>>b1>>b2;
        int flag=0;
        if(a2==a1+b1) flag++;
        if(b2==a1+b1) flag--;
        if(flag!=0){
            if(flag==1){
                a--;
                ansa++;
            }
            else {
                b--;
                ansb++;
            }
        }
        if(a<0||b<0){
            if(a<0){
                cout<<"A"<<endl;
                cout<<ansb<<endl;
            }
            else {
                cout<<"B"<<endl;
                cout<<ansa<<endl;
            }
            break;
        }
    }
    return 0;
}
/*
1 1
6
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
15 1 1 16
*/
