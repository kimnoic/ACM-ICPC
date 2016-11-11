#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 123
struct node{
    int x,y,step;
}mp[Max];
queue<node> q;
int n, m, cnt;
int ans1;
char a[15][15];
int vis[15][15];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
bool judge(int x,int y){
    if(x<n&&x>=0&&y<m&&y>=0)    return true;
    return false;
}
void dfs(int x,int y){
    vis[x][y] = 1;
    int i, j;
    for(i=0;i<4;i++){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(judge(xx,yy)&&a[xx][yy]=='#'&&!vis[xx][yy]){
            dfs(xx,yy);
        }
    }
}
int main(){
    int t,k = 1, cntk, flag;
    scanf("%d",&t);
    while(t--){
        while(!q.empty())   q.pop();
        cntk = 0;
        memset(vis,0,sizeof(vis));
        ans1=Max;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",a[i]);
            for(int j=0;j<m;j++){
                if(a[i][j]=='#'){
                    mp[cntk].x = i;
                    mp[cntk].y = j;
                    cntk++;
                }
            }
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='#'&&!vis[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        if(cnt>2){
            printf("Case %d: -1\n",k++);
            continue;
        }
        int cnt1;
        for(int i=0;i<cntk;i++){
            for(int j=i;j<cntk;j++){
                cnt1 = 0;
                flag = 0;
                memset(vis,0,sizeof(vis));
                vis[mp[i].x][mp[i].y] = 1;
                vis[mp[j].x][mp[j].y] = 1;
                mp[i].step = 0;
                mp[j].step = 0;
                q.push(mp[i]);
                q.push(mp[j]);
                while(!q.empty()){
                    node tt = q.front();
                    q.pop();
                    int ii;
                    for(ii=0;ii<4;ii++){
                        int ttx = tt.x + dir[ii][0];
                        int tty = tt.y + dir[ii][1];
                        if(judge(ttx,tty)&&a[ttx][tty]=='#'&&!vis[ttx][tty]){
                            vis[ttx][tty] = 1;
                            node temp;
                            temp.x = ttx;
                            temp.y = tty;
                            temp.step = tt.step+1;
                            q.push(temp);
                        }
                    }
                    if(tt.step>cnt1) cnt1 = tt.step;
                }
                for(int ii=0;ii<n;ii++){
                    for(int jj=0;jj<m;jj++){
                        if(a[ii][jj]=='#')
                            if(!vis[ii][jj]){
                                flag = 1;
                                break;
                        }
                    }
                    if(flag)    break;
                }
                if(flag)    continue;
                if(cnt1<ans1)    ans1 = cnt1;
            }
        }
        printf("Case %d: ",k++);
        if(ans1!=Max) cout<<ans1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
