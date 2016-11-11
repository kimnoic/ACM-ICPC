#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=26;

typedef struct Trie_Node{
    bool isWord;
    struct Trie_Node *next[MAX];
}Trie;
char s[50010][50];

void insert(Trie *root,char *word){
    Trie *p=root;
    int i=0;
    while(word[i]!='\0'){
        if(p->next[word[i]-'a']==NULL){
           Trie *temp=new Trie;
            for(int j=0;j<MAX;j++)
             temp->next[j]=NULL;
            temp->isWord=false;
            p->next[word[i]-'a']=temp;
        }
        p=p->next[word[i]-'a'];
        i++;
    }
    p->isWord=true;
}
bool search(Trie *root,char *word){
    Trie *p=root;
    for(int i=0;word[i]!='\0';i++){
        if(p->next[word[i]-'a']==NULL)//?
          return false;
        p=p->next[word[i]-'a'];
    }
    return p->isWord;
}
void del(Trie *root){
    for(int i=0;i<MAX;i++){
        if(root->next[i]!=NULL)
          del(root->next[i]);
    }
    free(root);
}
int main(){
    int i,j;
    int cnt=0;
    char str[50];
    Trie *root=new Trie;
    for(i=0;i<MAX;i++)
       root->next[i]=NULL;
    root->isWord=false;
    while(scanf("%s",s[cnt])!=EOF){
        insert(root,s[cnt++]);
    }
    for(i=0;i<cnt;i++){
        int len=strlen(s[i]);
        for(j=1;j<len-1;j++){
            char temp1[50]={'\0'};
            char temp2[50]={'\0'};
            strncpy(temp1,s[i],j);
            strncpy(temp2,s[i]+j,len-j);
            if(search(root,temp1)&&search(root,temp2)){
                printf("%s\n",s[i]);
                break;
            }
        }
    }
    del(root);
    return 0;
}
