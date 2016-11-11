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
#define rep(i,a,b) for(int i=a,tt=b;i<=tt;++i)
#define rrep(i,a,b) for(int i=a,tt=b;i>=tt;--i)
int mp[7][7];
int n,a,b;
struct pt{
    int u,v;
}p[110],q[110];
int d[9];
int st,cnt;
void judge(){
    cnt=0;
    st=0;
    for(int i=0;i<=6;i++){
        if(d[i]&1){cnt++;st=i;}else if(d[i]&&!st){st=i;}
        //cout<<st<<endl;

    }
}
void dfs(int u){
    for(int v=0;v<=6;v++){
        if(mp[u][v]){
            mp[u][v]--;
            mp[v][u]--;
            dfs(v);
            cnt++;
            q[cnt].u=u;
            q[cnt].v=v;
            //cout<<q[cnt].u<<" "<<q[cnt].v<<endl;
            //cout<<cnt<<endl;
        }
    }
}
int main(){
    cin>>n;
    memset(mp,0,sizeof(mp));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        mp[a][b]++;
        mp[b][a]++;
        p[i].u=a;
        p[i].v=b;
        d[a]++;
        d[b]++;
    }
    cnt=0;
    judge();
    if(cnt>2) cout<<"No solution";
    else{
        cnt=0;
        dfs(st);
        if(cnt<n) cout<<"No solution";
        else{
            for(int i=cnt;i>=1;i--){
                for(int j=1;j<=n;j++){
                    if(p[j].u==q[i].u&&p[j].v==q[i].v)
        {printf("%d +\n",j),p[j].u=-1;break;}
        else if(p[j].u==q[i].v&&p[j].v==q[i].u)
        {printf("%d -\n",j),p[j].u=-1;break;}
                        /*
                    if(p[i].u==q[j].u&&p[i].v==q[j].v){
                        cout<<j<<" +"<<endl;
                        q[j].u=-1;
                        break;
                    }
                    else if(p[i].u==q[j].v&&p[i].v==q[j].u){
                        cout<<j<<" -"<<endl;
                        q[j].u=-1;
                        break;
                    }
                    */
                }
            }
        }

    }
    return 0;
}
