#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define Max 1010
int f[Max];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(f,0,sizeof(f));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&f[i]);
        }
        if(n%2) f[++n]=0;
        sort(f+1,f+n+1);
        int ans=0;
        for(int i=n;i>=2;i-=2){
            ans^=(f[i]-f[i-1]-1);
        }
        if(!ans)
            printf("Bob will win\n");
        else
            printf("Georgia will win\n");
    }
    return 0;
}
