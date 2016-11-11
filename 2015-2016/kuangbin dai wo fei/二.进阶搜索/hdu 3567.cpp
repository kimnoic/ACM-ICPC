#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 404000
struct pt{
    char mp[3][3];
    int x,y;
    pt(){};
    pt(char *str){
        for(int i=0,xx=0,yy=0;str[i];i++){
            mp[xx][yy]=str[i];
            if(str[i]=='X'){
                x=xx;
                y=yy;
            }
            yy++;
            if(yy==3){
                xx++;
                yy=0;
            }
        }
    }
}S;
int fac[]={1,1,2,6,24,120,720,5040,40320};
int gethash(pt a){
    char str[10];
    int val=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            str[i*3+j]=a.mp[i][j];
            int cnt=0;
            for(int k=3*i+j-1;k>=0;k--){
                if(str[k]>str[3*i+j]) cnt++;
            }
            val+=fac[3*i+j]*cnt;
        }
    }
    return val;
}
int dx[4]={1,0,0,-1};int dy[4]={0,-1,1,0};
char dirr[5]="dlru";
int pre[10][Max];
char ans[10][Max];
bool vis[Max];

void bfs(int k){
    memset(pre[k],-1,sizeof(pre[k]));
    memset(vis,false,sizeof(vis));
    queue<pt>q;
    q.push(S);
    vis[gethash(S)]=true;
    while(!q.empty()){
        pt tm=q.front();
        q.pop();
        int tm_val=gethash(tm);

        for(int i=0;i<4;i++){
            pt tmp=tm;
            tmp.x+=dx[i];tmp.y+=dy[i];
            if(tmp.x>=3||tmp.x<0||tmp.y>=3||tmp.y<0) continue;
            tmp.mp[tm.x][tm.y]=tmp.mp[tmp.x][tmp.y];
            tmp.mp[tmp.x][tmp.y]='X';
            int tmp_val=gethash(tmp);
            if(vis[tmp_val]) continue;
            vis[tmp_val]=true;
            pre[k][tmp_val]=tm_val;
            ans[k][tmp_val]=dirr[i];
            q.push(tmp);
        }

    }
}

char str[11]="X12345678";
int num[11];

int main(){
    for(int i=0;;i++){
        S=pt(str);
        bfs(i);
        char t=str[i];
        if(i==8) break;
        str[i]=str[i+1];
        str[i+1]=t;
    }
    int _case=0;int t;
    cin>>t;
    while(t--){
        int k;
        scanf("%s",str);
        for(int i=0,p=0;str[i];i++){
            if(str[i]=='X'){
                k=i;
            }
            else num[str[i]-'0']=p++;
        }
        scanf("%s",str);
        for(int i=0;str[i];i++){
            if(str[i]=='X') continue;
            str[i]=num[str[i]-'0']+'1';
        }
        S=pt(str);
        //cout<<str<<endl;
        int val=gethash(S);
        //cout<<val<<endl;
        string ss="";
        int cnt=0;
        while(val!=-1){
            cnt++;
            ss+=ans[k][val];
            //cout<<val<<endl;
            val=pre[k][val];
        }

        reverse(ss.begin(), ss.end());
        cout<<"Case "<<++_case<<": "<<cnt-1<<endl;
        /*
        for(int i=ss.size()-2;i>=0;i--) cout<<ss[i];*/
            for(int i=1;i<ss.size();i++)cout<<ss[i];
        //cout<<endl;
        cout<<endl;
    }
    return 0;
}
