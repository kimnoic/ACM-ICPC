#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
double r[20];
double cal(double a,double b,double c){
    double p=(a+c+b)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double res=0;
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        res=0;
        for(int i=1;i<=n;i++){
            cin>>r[i];
        }
        sort(r+1,r+n+1);
        for(int i=n;i>2;i--){
            if(r[i-1]+r[i-2]>r[i]){
                res+=cal(r[i-1],r[i-2],r[i]);
                i-=2;
            }
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
