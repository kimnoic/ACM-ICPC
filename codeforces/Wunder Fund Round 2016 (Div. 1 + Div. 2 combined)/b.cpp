#include<bits/stdc++.h>
using namespace std;
#define Max 123
int n;
int f[Max][Max];
int g[Max];
int h[Max];
int ans;
bool judge(int a){
    for(int k=1;k<=n;k++)
        if(f[a][k]>ans)
            return 0;
    return 1;
}
int cnt=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>f[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){ans=i;
            if(g[j]==0 && judge(j)){
                    cnt++;
                g[j]=i;
                break;
            }}
    for(int i=1;i<=n;i++)
        cout<<g[i]<<" ";
    return 0;
}
