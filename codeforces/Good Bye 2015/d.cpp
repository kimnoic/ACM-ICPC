#include<bits/stdc++.h>
using namespace std;
#define Max 5005
int MOD=1e9+7;
char c;
int q[Max],f[Max][Max],a[Max][Max];
bool judge(int fx,int fy,int tx,int ty){
    if(fx<1)
        return 0;
    if(fy-fx<ty-tx)
        return 1;
    for(int i=0;i<=fy-fx;i++){
        if(q[fx+i]>q[tx+i])
            return 0;
        if(q[fx+i]<q[tx+i])
            return 1;

    }
    return 0;
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        f[1][i]=1;
        scanf(" %c",&c);
        q[i]=c-'0';
        //s[i]=rand()%10;
    }

    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(q[i]<=q[i-1]){
            f[i][i]=0;
        }
        else{
            f[i][i]=f[i-1][i-1];
            a[i][i]=1;
        }
    }
    int ss=1;
    for(int i=1;i<n;i++)
        for(int j=1;j<=n-i;j++)
            if(q[j]!=0){
                ss++;
                f[j][j+i]=f[j][j+i-1];
                if(j-i>=1 && !a[j][j+i-1])
                    f[j][j+i]=(f[j][j+i]+f[j-i][j-1])%MOD;
                if(judge(j-1-i,j-1,j,j+i)){
                    a[j][j+i]=1;
                    f[j][j+i]=(f[j][j+i]+f[j-i-1][j-1])%MOD;
                }
            }
    int i;
    int res=0;
    for(i=1;i<=n;i++)
        res=(res+f[i][n])%MOD;
    if(i>n&&ss>0)
    cout<<res<<endl;
    return 0;
}
