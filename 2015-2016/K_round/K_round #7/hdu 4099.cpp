#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
struct Node{
    int id;
    struct Node *next[10];
}p;
Node *head;
char c[100];
void tree_insert(char str[],int index){
    Node *t,*s=head;
    int len=strlen(str);
    for(int i=0;i<len&&i<41;i++){
        int id=str[i]-'0';
        if(s->next[id]==NULL){
            t=new Node;
            for(int j=0;j<10;j++){
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
    for(int i=0;i<len&&i<41;i++){
        int id=str[i]-'0';
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
    for(int i=0;i<10;i++){
        if(p->next[i]!=NULL){
            del_tree(p->next[i]);
        }
    }
    free(p);
}
void add(char a[],char b[],char back[]){
    int i,j,k;
    int x,y,z;
    int up;
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;
    up=0;
    while(i>=0||j>=0){
        if(i<0)x=0;
        else x=a[i]-'0';
        if(j<0)y=0;
        else y=b[j]-'0';
        z=x+y+up;
        c[k++]=z%10+'0';
        up=z/10;
        i--;
        j--;
    }
    if(up>0)c[k++]=up+'0';
    for(i=0;i<k;i++)back[i]=c[k-1-i];
    back[k]='\0';
}
char str[3][100];
void init(){
    head=new Node;
    for(int i=0;i<10;i++) head->next[i]=NULL;
    head->id=-1;
    str[0][0]='1';
    str[0][1]=0;
    tree_insert(str[0],0);
    str[1][0]='1';
    str[1][1]=0;
    tree_insert(str[1],1);
    for(int i=2;i<100000;i++){
        int len1=strlen(str[0]);
        int len2=strlen(str[1]);
        if(len2>60){
            str[1][len2-1]=0;
            str[0][len1-1]=0;
        }
        add(str[0],str[1],str[2]);
        tree_insert(str[2],i);
        strcpy(str[0],str[1]);
        strcpy(str[1],str[2]);
    }
}
int T;
char s[100];
int main(){
    init();
    cin>>T;
    int _case=0;
    while(T--){
        cin>>s;
        cout<<"Case #"<<++_case<<": ";
        cout<<tree_find(s)<<endl;
    }
    return 0;
}
