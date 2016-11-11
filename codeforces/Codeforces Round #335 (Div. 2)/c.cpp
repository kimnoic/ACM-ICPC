#include<bits/stdc++.h>
using namespace std;
#define Max 567
#define N 100100
int mp[Max][Max];
int dx[5]={0,0,1,0,-1},dy[5]={0,1,0,-1,0};

int m,n,fx,fy,x,y;
string s;
int g[N];
int check(char c){
    if(c=='D')return 2;
    else if(c=='U')return 4;
    else if(c=='L')return 3;
    else return 1;
}
int main(){
    memset(mp,-1,sizeof(mp));
    cin>>m>>n;
    cin>>fx>>fy;
    cin>>s;
    int len=s.length();
    int x=fx,y=fy;
    mp[fx][fy]=0;
    int cnt=0;
    for(int i=0;i<len;i++){
        int yy=y+dy[check(s[i])];
        int xx=x+dx[check(s[i])];
        if(xx>=1&&xx<=m&&yy>=1&&yy<=n){
            if(mp[xx][yy]==-1){
                mp[xx][yy]=i+1;
            }
            cnt++;
            x=xx;
            y=yy;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(mp[i][j]!=-1)
                g[mp[i][j]]++;
            else
                g[len]++;
    for(int i=0;i<=len;i++)
        cout<<g[i]<<" ";

    return 0;
}
