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
char a[12]="desu";
char b[12]="nanodesu";
char t[110];
int main(){
    int T;
    cin>>T;int _case=1;
    while(T--){

        scanf("%s",t);
        int len=strlen(t);
        int flag=0;
        int cnt=0;
        for(int i=len-1-3;i<len;i++){
            if(t[i]!=a[cnt]){
                flag=1;
                break;
            }
            cnt++;
        }
        cout<<"Case #"<<_case++<<": ";
        if(flag){
            printf("%s%s\n",t,b);
        }
        else {
            for(int i=0;i<len-4;i++){
                printf("%c",t[i]);
            }
            printf("%s\n",b);
        }
    }
    return 0;
}
