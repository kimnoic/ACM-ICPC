#include <map>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
map<string ,int >mp;
char t[3];
struct node{
    node* next[53];
    node(){
        for(int i=0;i<=52;i++){
            next[i]=NULL;
        }
    }
};
node *root,*p;
int T;
int num;
int key[1000];int cnt;
int countt=0;
int res=0;

void Insert(int k){
    if(p->next[k]==NULL){
        p->next[k]=new node();
        res++;
    }
    p=p->next[k];
}



void Delete(node *t){
    for(int i=0;i<=52;i++){
        if(t->next[i]!=NULL){
            Delete(t->next[i]);
            t->next[i]=NULL;
        }
    }
    delete t;
}

int hash(string s)   //传说中的hash
{
    int temp=0;
    if(s[1]=='0')
    {
        if(s[2]=='C') temp+=13*0;
        else if(s[2]=='D') temp+=13*1;
        else if(s[2]=='H') temp+=13*2;
        else temp+=13*3;
        return temp+=10;
    }

    if(s[1]=='C') temp+=13*0;
    else if(s[1]=='D') temp+=13*1;
    else if(s[1]=='H') temp+=13*2;
    else temp+=13*3;

    switch(s[0])
    {
        case 'A': temp+=1;break;
        case 'J': temp+=11;break;
        case 'Q': temp+=12;break;
        case 'K': temp+=13;break;
        default :temp+=s[0]-'0';break;
    }
    return temp;
}

int main(){
    while(cin>>T){
        if(T==0) break;
        root = new node();
        stack<string >q;
        res=0;
        while(T--){
            int n;
            cin>>n;
            cnt=0;
            for(int i=1;i<=n;i++){
                scanf("%s",t);
                q.push(t);
            }
            p=root;
            while(!q.empty()){
                int v=hash(q.top());
                Insert(v);
                q.pop();
            }
        }
        cout<<res<<endl;
        Delete(root);
    }
    return 0;
}
