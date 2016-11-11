#include <stdlib.h>
#include <stdio.h>

int main(){
    int i,j;
    for(i=1;i<=3;i++){
        for(j=3;j>i;j--){
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
