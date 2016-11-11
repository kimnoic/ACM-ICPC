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
#define Max 110
char mp[Max][Max];
int dx[10]={-1,0,1,0,1,1,-1,-1};
int dy[10]={0,1,0,-1,1,-1,1,-1};
int m,n;
void dfs(int x,int y){
    if(x<0||x>=m||y<0||y>=n||mp[x][y]!='@') return ;
    else {
        mp[x][y]='*';
        for(int i=0;i<8;i++){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    while(cin>>m>>n){
        if(m==0) break;
        int sum=0;
        for(int i=0;i<m;i++){
            scanf("%s",mp[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j]=='@'){
                    dfs(i,j);
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
