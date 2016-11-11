#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef struct pt{
    struct pt *next[2];
    bool code;
}Node;
int flag=0;
void tree_insert(Node *head,char str[]){
    Node *s=head;
    int len=strlen(str);
    int i=0;
    while(str[i]!='\0'){
        int id=str[i]-'0';
        if(s->next[id]==NULL){
            Node *t=new Node;
            for(int j=0;j<2;j++){
                t->next[j]=NULL;
            }
            t->code =false;
            s->next[id]=t;
        }
        else {
            if(s->next[id]->code==true){
                flag=1;
            }
        }
        s=s->next[id];
        i++;
    }
    s->code=true;
}
void del_tree(Node *p){
    for(int i=0;i<2;i++){
        if(p->next[i]!=NULL){
            del_tree(p->next[i]);
        }
    }
    free(p);
}
char str[20];
int main(){
    int _case=0;
    while(~scanf("%s",str)){
        Node *head=new Node;
        flag=0;
        for(int i=0;i<2;i++) head->next[i]=NULL;
        head->code =false;
        tree_insert(head,str);
        while(cin>>str){
            if(str[0]=='9') break;
            else tree_insert(head,str);
        }
        if(!flag)printf("Set %d is immediately decodable\n",++_case);
        else printf("Set %d is not immediately decodable\n",++_case);
        del_tree(head);//cout<<"asdf"<<endl;
    }
    return 0;
}
/*
01
10
010
0000
9
01
10
0010
0000
9
*/
