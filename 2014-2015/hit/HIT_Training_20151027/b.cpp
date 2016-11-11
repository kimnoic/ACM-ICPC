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
int T;
int m,n;
int _case=0;
int main(){
    cin>>T;
    while(T--){
        cin>>m>>n;
        cout<<"Case #"<<++_case<<": ";
        if(m==1){
            for(int i=1;i<=n;i++){
                printf("a");
            }
            printf("\n");
        }
        else if(m>=3){
            for(int i=1;i<=n/3;i++){
                printf("abc");
            }
            int res=n%3;
            if(res==1){
                printf("a\n");
            }
            else if(res==2){
                printf("ab\n");
            }
            else printf("\n");
        }
        else {
            if(n==1)
                printf("a");
            if(n==2)
                printf("ab");
            if(n==3)
                printf("aab");
            if(n==4)
                printf("aabb");
            if(n==5)
                printf("aaaba");
            if(n==6)
                printf("aaabab");
            if(n==7)
                printf("aaababb");
            if(n==8)
                printf("aaababbb");
            if(n>8){
                printf("aaaa");
                n-=4;
                while (n>=6){
                    n-=6;printf("babbaa");
                }
                if (n==1)
                    printf("a");
                if (n==2)
                    printf("aa");
                if (n==3)
                    printf("bab");
                if (n==4)
                    printf("babb");
                if (n==5)
                    printf("babba");
            }
            printf("\n");
        }
    }
    return 0;
}
