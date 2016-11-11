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
int mp[55][55][55];
char judge(int a){
    if(a<=26){
        return (char)(97+a-1);
    }
    else return (char)(65+a-27);
}
int main(){
    int n;
    cin>>n;
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[j][1][i]=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=2;k++){
                if(mp[j][2][i]==0){
                    mp[j][2][i]=i;
                }
            }
        }
    }
    cout<<n<<" "<<2<<" "<<n<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=2;k++){
                printf("%c",judge(mp[j][k][i]));
            }
            printf("\n");
            //cout<<endl;
        }
        printf("\n");
        //cout<<endl;
    }
    return 0;
}
