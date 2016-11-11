#include <bits/stdc++.h>
using namespace std;
int mp[10][10];
char tt[3];
int xx[9]={0,-1,-1,0,1,1,1,0,-1};
int yy[9]={0,0,1,1,1,0,-1,-1,-1};
int main(){
    while(~scanf(" %c%c",&tt[0],&tt[1])){
        memset(mp,0,sizeof(mp));
        int x=tt[0]-'a'+1;
        int y=tt[1]-'0';
        mp[x][y]=1;
        //scanf("%s",tt);

        scanf(" %c%c",&tt[0],&tt[1]);
        int tx=tt[0]-'a'+1;
        int ty=tt[1]-'0';
        int ttx=tx,tty=ty;
        while(1){
            ttx++;

            if(mp[ttx][tty]==1||ttx<1||ttx>8) break;
            mp[ttx][ty]=2;
        }
        ttx=tx;
        while(1){
            ttx--;
            if((ttx==x&&tty==y)||ttx<1||ttx>8) break;
            mp[ttx][ty]=2;
        }
        ttx=tx;
        while(1){
            tty++;
            if((tty==y&&ttx==x)||tty<1||tty>8) break;
            mp[tx][tty]=2;
        }
        tty=ty;
        while(1){
            tty--;
            if((tty==y&&ttx==x)||tty<1||tty>8) break;
            mp[tx][tty]=2;
        }
        for(int i=1;i<=8;i++){
            int tx=x+xx[i];
            int ty=y+yy[i];
            if(tx>=1&&tx<=8&&ty>=1&&ty<=8){
                mp[tx][ty]=1;
            }
        }

        scanf(" %c%c",&tt[0],&tt[1]);
        //scanf("%s",tt);
        x=tt[0]-'a'+1;
        y=tt[1]-'0';
        if(mp[x][y]==1){
            cout<<"Strange"<<endl;
        }
        else if(mp[x][y]==0){
            for(int i=1;i<=8;i++){
                tx=x+xx[i];
                ty=y+yy[i];
                if(tx>=1&&tx<=8&&ty>=1&&ty<=8){
                    if(mp[tx][ty]==0){
                        cout<<"Normal"<<endl;
                        break;
                    }

                }if(i==8){
                    cout<<"Stalemate"<<endl;
                    }

            }
            continue;
        }
        else {
            for(int i=1;i<=8;i++){
                tx=x+xx[i];
                ty=y+yy[i];
                if(tx>=1&&tx<=8&&ty>=1&&ty<=8){
                    if(mp[tx][ty]==0){
                        cout<<"Check"<<endl;
                        break;
                    }

                }if(i==8){
                    cout<<"Checkmate"<<endl;
                    }

            }
            continue;
        }
    }
    return 0;
}
