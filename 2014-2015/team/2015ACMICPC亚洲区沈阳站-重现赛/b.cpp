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
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
int T;
int n;
#define Max 510
int nex[Max][2010];
void kmp_pre(char x[],int m,int k){
    int i,j;
    j=nex[k][0]=-1;
    j=0;
    while(i<m){
        while(j!=-1 && x[i]!=x[j]) j=nex[k][j];
        nex[k][++i]=++j;
    }
}
bool kmp(char x[],int m,char y[],int n,int k1,int k2){
    int i,j;
    int ans=0;
    i=j=0;
    while(i<n){
        while(j!=-1&&y[i]!=x[j]) j=nex[k1][j];
        i++;j++;
        if(j==m){
            return true;
        }
    }
    return false;
}
int vis[Max];
char t[Max][2010];
int len[Max];
int main(){
    cin>>T;
    int _case=0;
    while(T--){
        int flag=0;
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%s",t[i]);
        }
        for(int i=1;i<=n;i++){
            len[i]=strlen(t[i]);
            kmp_pre(t[i],len[i],i);
        }
        int res=-1;
        printf("Case #%d: ",++_case);
        //cout<<"Case #"<<++_case<<": ";
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(vis[j]) continue;
                if(kmp(t[j],len[j],t[i],len[i],j,i)){
                    vis[j]=1;
                }
                else {
                    res=max(res,i);
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
