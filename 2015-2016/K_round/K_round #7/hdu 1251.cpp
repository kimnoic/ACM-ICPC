#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct Node{
    struct Node *br[26];
    int num;
};
Node *head;
void Tree_insert(char str[]){
    Node *t,*s=head;
    int i,j;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(s->br[id]==NULL){
            t=new Node;
            for(j=0;j<26;j++){
                t->br[j]=NULL;
            }
            t->num=0;
            s->br[id]=t;
        }
        s=s->br[id];
        s->num++;
    }
}
int Tree_Find(char str[]){
    Node *s=head;
    int count,i;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a';
        if(s->br[id]==NULL){
            return 0;
        }
        else{
            s=s->br[id];
            count=s->num;
        }
    }
    return count;
}
int main(){
    int i;
    head=new Node;
    for(i=0;i<26;i++){
        head->br[i]=NULL;
        head->num=0;
    }
    char str[12];
    while(gets(str)&&str[0])  Tree_insert(str);
    while(gets(str))  printf("%d\n",Tree_Find(str));
    return 0;
}
