#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define Max 128
#define N 500*210
int n;
struct Trie{
    int next[N][Max],fail[N],end[N];
    int root,L;
    int newnode(){
        for(int i = 0;i < Max;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init(){
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int id){
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++){
            if(next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode();
            now = next[now][buf[i]];
        }
        end[now]=id;
    }
    void build(){
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < Max;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else{
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while( !Q.empty() ){
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < Max;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    bool vis[510];

    bool query(char buf[],int id){
        bool flag=false;
        memset(vis,false,sizeof(vis));
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++){
            now = next[now][buf[i]];
            int temp = now;
            while( temp != root ){
                if(end[temp]!=-1){
                    vis[end[temp]]=true;
                    flag=true;
                }
                temp=fail[temp];
            }
        }
        if(!flag) return false;
        printf("web %d:",id);
        for(int i=1;i<=n;i++){
            if(vis[i]){
                printf(" %d",i);
            }
        }
        printf("\n");
        return true;
    }
};
char buf[10010];
Trie ac;
int main(){
    int T;
    scanf("%d",&n);
    ac.init();
    for(int i=1;i<=n;i++){
        scanf("%s",buf);
        ac.insert(buf,i);
    }
    ac.build();
    int m;
    cin>>m;
    int cnt=0;
    for(int i=1;i<=m;i++){
        scanf("%s",buf);
        if(ac.query(buf,i)){
            cnt++;
        }
    }
    cout<<"total: "<<cnt<<endl;
    return 0;
}
