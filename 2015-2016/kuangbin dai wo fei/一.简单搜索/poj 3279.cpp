#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 30
int mp[Max][Max];
int tmp[Max][Max];
int cha[Max][Max];
int ans[Max][Max];
int m,n;
int res=0;
bool judge(int x,int y){
    if(x>=1&&x<=m&&y>=1&&y<=n) return true;
    else return false;
}
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};

void update(int x,int y){
    for(int i=0;i<4;i++){
        if(judge(x+xx[i],y+yy[i])){
            tmp[x+xx[i]][y+yy[i]]^=1;
        }
    }
    tmp[x][y]^=1;
}
int f=0;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf(" %d",&mp[i][j]);
        }
    }
    f=0;
    res=m*n+1;
    memset(cha,0,sizeof(cha));
    for(int i=0;i<(1<<n);i++){
        memset(tmp,0,sizeof(tmp));
        memset(cha,0,sizeof(cha));
        int k=i;
        int cnt=0,tm=0;
        for(int j=n;k>0;j--){
            int p=k%2;
            cha[1][j]=p;
            k/=2;
            cnt++;
        }
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                tmp[j][k]=mp[j][k];
            }
        }
        for(int j=1;j<=n;j++){
            if(cha[1][j]){
                update(1,j);
                tm++;
            }
        }
        for(int j=1;j<m;j++){
            //cout<<j<<endl;
            for(int k=1;k<=n;k++){
                if(tmp[j][k]){
                    update(j+1,k);
                    cha[j+1][k]=1;
                    tm++;
                }
                //cout<<cha[j+1][k]<<" ";
            }
            //cout<<endl;
        }
        int flag=0;
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(tmp[j][k]){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag)continue;
        f=1;
        if(tm<res){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=n;k++){
                    ans[j][k]=cha[j][k];
                }
            }
            res=tm;
        }
    }
    if(!f){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d",ans[i][j]);
            if(j!=n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
