#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
using namespace std;
int main(){
    double a;
    int cnt=0;
    double sum=0;
    while(~scanf("%lf",&a)){
        sum+=a;
        cnt++;
    }
    printf("$%.2f",sum/cnt);
    return 0;
}
