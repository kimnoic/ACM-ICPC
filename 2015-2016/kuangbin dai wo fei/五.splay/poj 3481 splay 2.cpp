#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=8e4+100;
const int mod=1000000;
struct SplayTree {
    int sz[MAXN];
    int ch[MAXN][2];
    int pre[MAXN];
    int rt,top;
    inline void up(int x){
        sz[x]  = cnt[x]  + sz[ ch[x][0] ] + sz[ ch[x][1] ];
    }
    inline void Rotate(int x,int f){
        int y=pre[x];
        ch[y][!f] = ch[x][f];
        pre[ ch[x][f] ] = y;
        pre[x] = pre[y];
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] =x;
        ch[x][f] = y;
        pre[y] = x;
        up(y);
    }
    inline void Splay(int x,int goal){//将x旋转到goal的下面
        while(pre[x] != goal){
            if(pre[pre[x]] == goal) Rotate(x , ch[pre[x]][0] == x);
            else   {
                int y=pre[x],z=pre[y];
                int f = (ch[z][0]==y);
                if(ch[y][f] == x) Rotate(x,!f),Rotate(x,f);
                else Rotate(y,f),Rotate(x,f);
            }
        }
        up(x);
        if(goal==0) rt=x;
    }
    inline void RTO(int k,int goal){//将第k位数旋转到goal的下面
        int x=rt;
        while(sz[ ch[x][0] ] != k-1) {
            if(k < sz[ ch[x][0] ]+1) x=ch[x][0];
            else {
                k-=(sz[ ch[x][0] ]+1);
                x = ch[x][1];
            }
        }
        Splay(x,goal);
    }
    inline void vist(int x){
        if(x){
            printf("结点%2d : 左儿子  %2d   右儿子  %2d   %2d sz=%d\n",x,ch[x][0],ch[x][1],val[x],sz[x]);
            vist(ch[x][0]);
            vist(ch[x][1]);
        }
    }
    inline void Newnode(int &x,int c){
        x=++top;
        ch[x][0] = ch[x][1] = pre[x] = 0;
        sz[x]=1; cnt[x]=1;
        val[x] = c;
    }
    inline void init(){
        ans=0;type=-1;
        ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
        rt=top=0; cnt[0]=0;
        Newnode(rt,-INF);
        Newnode(ch[rt][1],INF);
        pre[top]=rt;
        sz[rt]=2;
    }
    inline void Insert(int &x,int key,int f){
        if(!x) {
            Newnode(x,key);
            pre[x]=f;
            Splay(x,0);
            return ;
        }
        if(key==val[x]){
            cnt[x]++;
            sz[x]++;
            return ;
        }else if(key<val[x]) {
            Insert(ch[x][0],key,x);
        } else {
            Insert(ch[x][1],key,x);
        }
        up(x);
    }

    void Del(){  //删除根结点
　　　　　　int t=rt;
         if(ch[rt][1]) {
             rt=ch[rt][1];
             RTO(1,0);
             ch[rt][0]=ch[t][0];
             if(ch[rt][0]) pre[ch[rt][0]]=rt;
         }
         else rt=ch[rt][0];
         pre[rt]=0;
         up(rt);
    }
    void findpre(int x,int key,int &ans){  //找key前趋
        if(!x)  return ;
        if(val[x] <= key){
            ans=x;
            findpre(ch[x][1],key,ans);
        } else
            findpre(ch[x][0],key,ans);
    }
    void findsucc(int x,int key,int &ans){  //找key后继
        if(!x) return ;
        if(val[x]>=key) {
            ans=x;
            findsucc(ch[x][0],key,ans);
        } else
            findsucc(ch[x][1],key,ans);
    }
}
SplayTree t;
int main(){
    t.init();

    return 0;
}

　　
