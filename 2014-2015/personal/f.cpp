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
#define rson l,m,rt*2
#define lson m+1,r,rt*2+1
#define Max 100010
int a[Max];
int f[Max],g[Max];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++){
            scanf("%d",a[i]);
        }
        for(int i=2;i<=n;i++){
            if(a[i]>=a[i-1]){
                f[i]=f[i-1]+1;
            }
            else {
                break;
            }
        }
        for(int i=n;i>=2;i--){
            if(a[i]<=a[i-1]){
                g[i-1]=g[i]+1;
            }
            else break;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            if(f[i]+g[i]==n-1){
                flag=1;
                break;
            }
        }
        if(flag){
            printf("YES\n");
            continue;
        }
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int i=2;i<=n;i++){
            if(a[i]<=a[i-1]){
                f[i]=f[i-1]+1;
            }
            else {
                break;
            }
        }
        for(int i=n;i>=2;i--){
            if(a[i]>=a[i-1]){
                g[i-1]=g[i]+1;
            }
            else break;
        }
        for(int i=1;i<=n;i++){
            if(f[i]+g[i]==n-1){
                flag=1;
                break;
            }
        }
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
