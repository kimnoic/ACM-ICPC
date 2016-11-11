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
string tm;
struct pt{
    int pos;
    string path;
    string str;
    pt(){
        pos=0;
    }
}temp,qq;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int pos;
char res[4]={'u','d','l','r'},s[2];
map<string,struct pt>mp;
void bfs(){
    queue<struct pt>q;
    qq.path="";
    qq.pos=pos;
    qq.str=tm;
    string mid;
    mp[tm].pos=1;
    q.push(qq);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=temp.pos/3+dx[i];
            int y=temp.pos%3+dy[i];
            if(x<0||y>2||x>2||y<0) continue;
            mid=temp.str;
            pos=temp.pos;
            if(i==0){
                mid[pos+3]=temp.str[pos];
                mid[pos]=temp.str[pos+3];
                qq.pos=pos+3;
            }
            else if(i==1){
                mid[pos-3]=temp.str[pos];
                mid[pos]=temp.str[pos-3];
                qq.pos=pos-3;
            }
            else if(i==2){
                mid[pos+1]=temp.str[pos];
                mid[pos]=temp.str[pos+1];
                qq.pos =pos+1;
            }
            else{
                mid[pos-1]=temp.str[pos];
                mid[pos]=temp.str[pos-1];
                qq.pos =pos-1;
            }
            if(mp[mid].pos==0){qq.str=mid;
                qq.path=temp.path;
                qq.path+=res[i];
                mp[mid].path=qq.path;
                mp[mid].pos=1;
                q.push(qq);
            }
        }
    }
}
int cnt;
void init(){
    tm="12345678x";
    pos=8;
    bfs();
    tm="";
    cnt=0;
}
int main(){
    init();
    while(scanf("%s",s)!=EOF){
         cnt++;
         tm+=s[0];
         if(cnt==9){
            if(mp[tm].pos==0)
                cout<<"unsolvable"<<endl;
            else{
                for(int i=mp[tm].path.size()-1;i>=0;i--)
                    cout<<mp[tm].path[i];
                cout<<endl;
            }
            tm="";
            cnt=0;
        }
    }
    return 0;
}
