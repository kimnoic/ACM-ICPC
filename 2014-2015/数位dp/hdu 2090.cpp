#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char a[233];
double res=0,c,b;
int main(){
    while(scanf(" %s%lf%lf",a,&b,&c)!=EOF){
        res+=b*c;
    }
    printf("%.1lf\n",res);
    return 0;
}
