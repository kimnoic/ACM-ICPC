#include <bits/stdc++.h>
using namespace std;

struct point{
    int z,x,y;
    point(int a,int b,int c){
        z = a;
        x = b;
        y = c;
    }
};

int l,r,c;
int sl,sx,sy,el,ex,ey;
bool mapp[22][22][22];
int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};



bool judge(int z,int x,int y){
    return z>=1&&z<=l&&x>=1&&x<=r&&y>=1&&y<=c&&mapp[z][x][y]==true;
}

void init(){
    memset(mapp,false,sizeof(mapp));
}

void getSingle(){
    char ch;
    for (int i = 1;i <= l;i++){
        for (int j = 1;j <= r;j++){
            for (int k = 1;k <= c;k++){
                ch = getchar();
                if (ch == '.')
                    mapp[i][j][k] = true;
                else if (ch == 'S'){
                    mapp[i][j][k] = true;
                    sl = i;
                    sx = j;
                    sy = k;
                }else if (ch == 'E'){
                    mapp[i][j][k] = true;
                    el = i;
                    ex = j;
                    ey = k;
                }
            }
            getchar();
        }
        if (i != l)
            getchar();
    }
}

int bfs(){
    int cnt = 0;
    int nowst = 0;

    queue<point>q;
    queue<int>step;

    while (!q.empty())
        q.pop();
    while (!step.empty())
        step.pop();

    q.push(point(sl,sx,sy));
    step.push(0);
    mapp[sl][sx][sy] = false;
    while (!q.empty()){
        point tmp = q.front();
        nowst = step.front();
        q.pop();
        step.pop();
        int az = tmp.z;
        int ax = tmp.x;
        int ay = tmp.y;


        if (az==el&&ax==ex&&ay==ey)
            return nowst;
        mapp[az][ax][ay] = false;
        for (int i = 0;i < 6;i++){

            az = tmp.z + dir[i][0];
            ax = tmp.x + dir[i][1];
            ay = tmp.y + dir[i][2];
            if (judge(az,ax,ay)){
                q.push(point(az,ax,ay));
                step.push(nowst+1);
            }
        }
    }
    return -1;
}

int main(){
    while (scanf("%d%d%d",&l,&r,&c) != EOF && l && r && c){
        init();
        getchar();
        getSingle();
        int ans = bfs();
        if (ans == -1)
            printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
}
