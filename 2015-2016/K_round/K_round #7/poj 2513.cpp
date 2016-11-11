#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int maxn = 500010;
int fa[maxn];

struct Node{
    int id;
    struct Node *next[26];
}p;
Node *head;
void tree_insert(char str[],int index){
    Node *t,*s=head;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(s->next[id]==NULL){
            t=new Node;
            for(int j=0;j<26;j++){
                t->next[j]=NULL;
            }
            t->id=-1;
            s->next[id]=t;
        }
        s=s->next[id];
        if(s->id<0)s->id=index;
    }
}
int tree_find(char str[]){
    Node *s=head;
    int cnt;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(s->next[id]==NULL){
            return -1;
        }
        else {
            s=s->next[id];
            cnt=s->id;
        }
    }
    return cnt;
}
void del_tree(Node *p){
    for(int i=0;i<26;i++){
        if(p->next[i]!=NULL){
            del_tree(p->next[i]);
        }
    }
    free(p);
}
char str[11];int deg[maxn];
void init(){
    for(int i=0;i<maxn;i++) fa[i]=i;
    head=new Node;
    head->id=-1;
    memset(deg,0,sizeof(deg));
    for(int i=0;i<26;i++) head->next[i]=NULL;
}

int findf(int u){
    if(fa[u]==u) return u;
    else return fa[u]=findf(fa[u]);
}
void uni(int u,int v){
    int fau=findf(u);
    int fav=findf(v);
    fa[fau]=fav;
}
int main(){
    init();
    int tol=0;
    while(~scanf("%s",str)){
        //cout<<endl;
        int tempa=tree_find(str);
        if(tempa==-1){
            tol++;
            tempa=tol;
            tree_insert(str,tol);
        }
        deg[tempa]++;
        //cout<<tempa<<endl;
        scanf("%s",str);
        int tempb=tree_find(str);
        if(tempb==-1){
            tol++;
            tempb=tol;
            tree_insert(str,tol);
        }
        deg[tempb]++;
        uni(tempa,tempb);
    }
    int sum=0;
    for(int i=1;i<=tol;i++){
        sum+=deg[i]%2;
    }
    if(sum>2){
        cout<<"Impossible";
        return 0;
    }
    int f=findf(tol);
    for(int i=1;i<tol;i++){
        if(findf(i)!=f){
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible";
    return 0;
}
