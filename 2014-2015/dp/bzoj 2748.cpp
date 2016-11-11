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
int n,st,m;
#define Max 1010
int val[Max];
int c[51][Max];

int main(){
    memset(c,0,sizeof(c));
    cin>>n>>st>>m;
    for(int i=1;i<=n;i++) cin>>val[i];
    c[0][st]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j+val[i]<=m){
                if(c[i-1][j]){
                    c[i][j+val[i]]=1;
                }
            }
            if(j-val[i]>=0){
                if(c[i-1][j]){
                    c[i][j-val[i]]=1;
                }
            }
        }
    }
    for(int i=m;i>=0;i--){
        if(c[n][i]) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
