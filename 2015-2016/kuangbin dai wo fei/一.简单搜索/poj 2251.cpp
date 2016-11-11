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
using namespace std;
#define Max 33
char mp[Max][Max][Max];
struct pt{
    int x,y,z,step;
};
int dx[10]={-1,0,1,0,0,0};
int dy[10]={0,1,0,-1,0,0};
int dz[10]={0,0,0,0,1,-1};
int x,y,z;
pt st,en;
int bfs(){
    queue<pt>q;
    while(!q.empty()){
        q.pop();
    }
    q.push(st);
    while(1){
        if(q.empty()) return 0;
        pt p=q.front();
        if(p.x==en.x&&p.y==en.y&&p.z==en.z) return p.step;
        q.pop();
        for(int i=0;i<6;i++){
            if((p.x+dx[i]>=1&&p.x+dx[i]<=x)&&(p.y+dy[i]>=1&&p.y+dy[i]<=y)&&(p.z+dz[i]>=1&&p.z+dz[i]<=z)&&(mp[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]]!='#')){
                pt r;
                r.x=p.x+dx[i];
                r.y=p.y+dy[i];
                r.z=p.z+dz[i];
                r.step=p.step+1;
                q.push(r);
                mp[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]]='#';
            }
        }
    }
}
int main(){
    while(scanf("%d%d%d",&z,&y,&x)){
        if(x==0&&y==0&&z==0) break;
        for(int i=1;i<=z;i++){
            for(int j=1;j<=y;j++){
                for(int k=1;k<=x;k++){
                    scanf(" %c",&mp[k][j][i]);
                    if(mp[k][j][i]=='S'){
                        st.x=k;
                        st.y=j;
                        st.z=i;
                        st.step=0;
                    }
                    else if(mp[k][j][i]=='E'){
                        en.x=k;
                        en.y=j;
                        en.z=i;
                    }
                }
            }
        }
        int ans=bfs();
        if(!ans) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
