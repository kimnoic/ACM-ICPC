#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
int vis[1010];
vector <int> t[1010];
int main(){
    while(cin>>n){
        int a,b;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=1000;i++)
        t[i].clear();
        int cnt=0;
        for(int i=1;i<n;i++){
            cin>>a>>b;
            t[a].push_back(b);
            t[b].push_back(a);
        }
        int flag=0;
        if(t[1].size()>=2){
            for(int i=0;i<t[1].size();i++){
                if(t[t[1][i]].size()>=2){
                    flag=1;
                    break;
                }
                else vis[t[1][i]]=1;
            }
        }
        if(!flag)
        {for(int i=2;i<=n;i++){
            if(t[i].size()>=3&&vis[i]==0){cnt=0;
                for(int j=0;j<t[i].size();j++){
                    if(t[i][j]==1) cnt++;
                    else if(t[t[i][j]].size()>=2){
                        cnt++;
                    }
                    else vis[t[i][j]]=1;
                    if(cnt>=2){
                        flag=1;
                        break;
                    }
                }
                if(flag) break;
            }
        }}
        if(!flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
