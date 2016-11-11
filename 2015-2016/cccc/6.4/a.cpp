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
char a[233];
int main(){
    cin>>a;
    int len=strlen(a);
    double k=1;
    if(a[0]=='-') k+=0.5;
    double ans=0,sum=0;
    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            if(a[i]=='2'){
                ans++;
            }
            sum++;
        }
    }
    if((a[len-1]-'0')%2==0) k*=2;

    double d=(ans/sum*k*100);
    printf("%.2f%%",d);
    return 0;
}
