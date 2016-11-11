#include <bits/stdc++.h>
using namespace std;
#define Max 1000
char c[Max][Max];
char judge(char a){
    if(a=='+') return '*';
    else return '+';
}
int cnt=2;
int main(){
    int k;
    cin>>k;
    c[1][1]='+';
    c[2][1]='+';
    c[1][2]='+';
    c[2][2]='-';
    for(int i=2;i<=k;i++){
        int a=1;
        for(int j=cnt+1;j<=cnt*2;j++){
            if(2*a<=cnt){

            }
        }
    }
    return 0;
}
