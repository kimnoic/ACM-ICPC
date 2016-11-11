#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define Max 10

using namespace std;
struct node{
    int next[Max];
    int flag;
}trie[100000];
bool f;
int num;
struct node root;
void insert(char *s){
    int len = strlen(s);
    int p=0;
    for(int i=0;i<len;i++){
            //cout<<i<<endl;
        int tem=s[i]-'0';
        if(trie[p].next[tem]!=-1){
            //cout<<i<<endl;
            p=trie[p].next[tem];
            if(i==len-1){
                f=false;
                return ;
            }
            if(trie[p].flag==1){
                f=false;
                return ;
            }
        }
        else {
            trie[p].next[tem]=++num;
            p=num;
        }
        if(i==len-1){
            trie[p].flag=1;
        }
    }
}
int T,n;
char t[11];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        f=true;
        num=0;
        memset(trie,-1,sizeof(trie));
        for(int i=1;i<=n;i++){
            scanf("%s",t);
            if(f)
            insert(t);
            //else cout<<i<<endl;
        }
        if(f)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
