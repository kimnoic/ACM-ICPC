#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define Max 233
#define maxx 999999999
int a[Max],b[Max];long long f[Max][Max];
int T;
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                f[i][j]=maxx;
            }
        }
        for(int len=0;len<=n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                for(int k=i;k<=j;k++){
                    f[i][j]=min(f[i][k-1]+f[k+1][j]+b[i-1]+b[j+1]+a[k],f[i][j]);
                }
            }
        }
        cout<<"Case #"<<++_case<<": "<<f[1][n]<<endl;
    }
    return 0;
}
