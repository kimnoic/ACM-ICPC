#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 10
typedef struct Trie
{
    bool flag;//从根到此是否为一个单词
    Trie *next[Max];
}Trie;
Trie *root;
void init(){
    root = (Trie *)malloc(sizeof(Trie));
    root->flag=false;
    for(int i=0;i<10;i++){
        root->next[i]=NULL;
    }
}
bool f;
void insert(char *word)
{
    Trie *tem = root;
    for(int j=0;j<strlen(word);j++)
    {
        if(tem->next[word[j]-'0']==NULL)
        {
            Trie *cur = (Trie *)malloc(sizeof(Trie));
            for(int i=0;i<Max;i++)
            cur->next[i]=NULL;
            cur->flag=false;
            tem->next[word[j]-'0']=cur;
        }
        tem = tem->next[word[j]-'0'];
        if(tem->flag) f=false;
    }
    tem->flag=true;
}
int T;
int n;
char t[12];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        f=true;
        init();
        for(int i=1;i<=n;i++){
            scanf("%s",t);
            if(f)
            insert(t);
        }
        if(f)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
