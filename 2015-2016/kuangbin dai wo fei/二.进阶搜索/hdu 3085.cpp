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
#define Max 805
#define REP(i,a,n) for(int i=a;i<=n;i++)
#define MP(a,b) make_pair(a,b)
struct Node{
    int x,y;
    Node (){};
    Node (int a,int b):x(a),y(b){};
}mm,gg,zz[2];
bool vis[Max][Max][2];
int n,m,step;
char mp[Max][Max];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int ,int > >q[2];
bool judge(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&mp[x][y]!='X'){
        REP(i,0,1){
            if(abs(x-zz[i].x)+abs(y-zz[i].y)<=2*step) return false;
        }
        return true;
    }
    return false;
}
bool bfs(int num){
    int T=q[num].size();
    while(T--){
        int x=q[num].front().first,y=q[num].front().second;
        q[num].pop();
        if(!judge(x,y)) continue;
        REP(i,0,3){
            int xx=x+dir[i][0],yy=y+dir[i][1];
            if(judge(xx,yy)){
                if(!vis[xx][yy][num]){
                    if(vis[xx][yy][num^1]) return true;
                    vis[xx][yy][num]=true;
                    q[num].push(MP(xx,yy));
                }
            }
        }
    }
    return false;
}
int solve(){
    memset(vis,false,sizeof(vis));
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    q[0].push(MP(mm.x,mm.y));
    q[1].push(MP(gg.x,gg.y));
    step=0;
    while(!q[0].empty()||!q[1].empty()){
        step++;
        if(bfs(0)) return step;
        if(bfs(0)) return step;
        if(bfs(0)) return step;
        if(bfs(1)) return step;
    }
    return -1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int cnt=0;
        REP(i,0,n-1){
            scanf("%s",mp[i]);
            REP(j,0,m-1){
                if(mp[i][j]=='M') mm=Node(i,j);
                else if(mp[i][j]=='G') gg=Node(i,j);
                else if(mp[i][j]=='Z') zz[cnt++]=Node(i,j);
            }
        }
        cout<<solve()<<endl;
    }
    return 0;
}
