#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define Max 55
#define N 1010
long long dp[Max][N];
long long t1[Max][N];
long long w[Max][N];
void init(){
    for(int i=1;i<=1000;i++){
        dp[1][i]=i;w[1][i]=i;
        t1[1][i]=t1[1][i-1]+w[1][i];
    }

    for(int i=2;i<=50;i++){
        for(int j=1;j<=1000;j++){
            w[i][j]=j+t1[i-1][j-1];
            t1[i][j]=t1[i][j-1]+w[i][j];

        }
    }
    for(int i=2;i<=50;i++){
        int last=1;
        for(int j=1;last<=1000;j++){
            while(last<=w[i][j]){
                dp[i][last]=j;
                last++;
                if(last>1000)
                    break;
            }
        }
    }
}
int n,a,b;
int main(){
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<"Case "<<i<<": "<<dp[a][b]<<endl;
    }
    return 0;
}
