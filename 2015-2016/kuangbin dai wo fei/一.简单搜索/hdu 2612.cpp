#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define Max 201
using namespace std;
int n,m,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char mp[Max][Max];
bool vis[Max][Max];
int a[Max][Max];
#define MAXN 2010
struct node{
    int x,y,cnt;
}f[MAXN];

node f1,f2;

queue<node> Q;
void bfs(){
    while(!Q.empty()){
        node t=Q.front(),temp;
        Q.pop();
        if(mp[t.x][t.y]=='@'){
            a[t.x][t.y]+=t.cnt;
        }
        for(int k=0;k<4;k++){
            int i=t.x+dir[k][0];
            int j=t.y+dir[k][1];
            if(i>n||i<1||j>m||j<1||vis[i][j]||mp[i][j]=='#') continue;
            vis[i][j]=1;
            temp.x=i;temp.y=j;temp.cnt=t.cnt+1;
            Q.push(temp);
        }
    }
    return ;
}
int main(){
    int num;
    while(cin>>n>>m){
        num=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='M'){
                    f1.x=i;f1.y=j;
                    f1.cnt=0;
                }
                if(mp[i][j]=='Y'){
                    f2.x=i;f2.y=j;
                    f2.cnt=0;
                }
                if(mp[i][j]=='@'){
                    f[num].x=i;f[num].y=j;
                    num++;
                }
            }
        memset(a,0,sizeof(a));
        while(!Q.empty()) Q.pop();
        memset(vis,0,sizeof(vis));
        vis[f1.x][f1.y]=1;
        Q.push(f1);
        bfs( );
        memset(vis,0,sizeof(vis));
        while(!Q.empty()) Q.pop();
        vis[f2.x][f2.y]=1;
        Q.push(f2);
        bfs();
        long long max1=99999999999999;
        for(int i=0;i<num;i++){
            if(a[f[i].x][f[i].y]!=0&&a[f[i].x][f[i].y]<max1)
                max1=a[f[i].x][f[i].y];
        }
        cout<<max1*11<<endl;
    }
    return 0;
}
