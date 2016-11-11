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
const int maxn = 10010;
char t[maxn];
char a[5]="GPLT";
int sum[5];
int main(){
    cin>>t;
    int len=strlen(t);
    for(int i=0;i<len;i++){
        if(t[i]>='a'&&t[i]<='z'){
            t[i]='A'+t[i]-'a';
        }
    }
    int k=0;
    int cnt=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++){
            if(t[i]==a[j]){
                sum[j]++;
                break;
            }
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<4;j++){
            if(sum[j]){
                sum[j]--;
                cout<<a[j];
            }
        }
    }
    return 0;
}
