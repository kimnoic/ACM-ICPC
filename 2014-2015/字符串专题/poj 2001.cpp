#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define Max 26
struct node
{
    bool flag;
    int cnt;
    node *next[Max];
    node (){
        cnt=0;
        flag=false;
        for(int i=0;i<Max;i++){
            next[i]=NULL;
        }
    }
};
char t[10100][22];
node *root,*p;
void Insert(char s[]){
    p=root;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        //cout<<i<<endl;

        if(p->next[s[i]-'a']==NULL)
            p->next[s[i]-'a']=new node();
        p=p->next[s[i]-'a'];p->cnt++;
        if(i==len-1) p->flag=true;
    }
}
void search(char s[]){
    int len=strlen(s);
    p=root;
    for(int i=0;i<len;i++){
        printf("%c",s[i]);
        if(p->next[s[i]-'a']->cnt==1){
            printf("\n");
            return ;
        }
        else if(i==len-1){
            printf("\n");
            return ;
        }
        else p=p->next[s[i]-'a'];
    }
}
int main(){
    int cnt=0;
    root = new node();
    while(~scanf("%s",t[++cnt])){
        //cout<<t[cnt]<<endl;
        Insert(t[cnt]);
    }
    for(int i=1;i<=cnt;i++){
        printf("%s ",t[i]);

        search(t[i]);
    }
    return 0;
}
