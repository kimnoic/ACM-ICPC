#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define kind 26
struct node{
    node *fail;
    node *next[kind];
    int count;
    node(){
        fail=NULL;
        count=0;
        memset(next,NULL,sizeof(next));
    }
}*q[500001];
char key[51];
char str[1000001];
int head,tail;
void Insert(char *str,node *root){
    node *p=root;
    int i=0,index;
    while(str[i]){
        index=str[i]-'a';
        if(p->next[index]==NULL) p->next[index]=new node();
        p=p->next[index];
        i++;
    }
    p->count++;
}
void build(node *root){
    int i;
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail){
        node *temp=q[tail++];
        node *p=NULL;
        for(i=0;i<kind;i++){
            if(temp->next[i]!=NULL){
                if(temp==root) temp->next[i]->fail=root;
                else{
                    p=temp->fail;
                    while(p!=NULL){
                        if(p->next[i]!=NULL){
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];
            }
        }
    }
}
int query(node *root){
    int i=0,cnt=0,index,len=strlen(str);
    node *p=root;
    while(str[i]){
        index=str[i]-'a';
        while(p->next[index]==NULL && p!=root) p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        node *temp=p;
        while(temp!=root && temp->count!=-1){
            cnt+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        head=tail=0;
        node *root=new node();
        for(int i=1;i<=n;i++){
            cin>>key;
            Insert(key,root);
        }
        build(root);
        cin>>str;
        cout<<query(root)<<endl;
    }
    return 0;
}
