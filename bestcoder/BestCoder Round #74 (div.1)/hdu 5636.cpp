#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define Max 10
int a[Max],mp[Max][Max];
int n,m;
long long ans,res;
const int MOD=1e9+7;
int main(){
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=6;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=6;i++){
            for(int j=1;j<=6;j++){

                mp[i][j]=abs(a[i]-a[j]);
            }
        }
        if(a[1]!=a[2]) mp[1][2]=mp[2][1]=1;
        if(a[3]!=a[4]) mp[3][4]=mp[4][3]=1;
        if(a[5]!=a[6]) mp[5][6]=mp[6][5]=1;
        for(int k=1;k<=6;k++){
            for(int i=1;i<=6;i++){
                for(int j=1;j<=6;j++){
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
        }
        int l,r;
        int t=0;
        while(m--){
            scanf("%d%d",&l,&r);
            t++;
            res=abs(l-r);
            for(int i=1;i<=6;i++)
                for(int j=1;j<=6;j++)
            res=min(res,(long long)(abs(a[i]-l)+mp[i][j]+abs(a[j]-r)));
            ans+=t*res;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
