#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAXN = 100010;
struct Node;
Node * null;
struct Node {
    Node *ch[2],*fa;
    int size;
    int rev;
    Node (){
        ch[0]=ch[1]=fa=null;
        rev=0;
    }
    inline void push_up(){
        if(this==null) return ;
        size=ch[0]->size+ch[1]->size+1;
    }
    inline void setc(Node *p,int d){
        ch[d]=p;
        p->fa=this;
    }
    inline bool d(){
        return fa->ch[1]==this;
    }
    void clear(){
        size=1;
        ch[0]=ch[1]=fa=null;
        rev=0;
    }
    void Update_Rev(){
        if(this==null)return ;
        swap(ch[0],ch[1]);
        rev^=1;
    }
    inline void push_down(){
        if(this==null) return ;
        if(rev){
            ch[0]->Update_Rev();
            ch[1]->Update_Rev();
            rev=0;
        }
    }
    inline bool isroot(){
        return fa==null||this!=fa->ch[0]&&this!=fa->ch[1];
    }
};
inline void rotate(Node * x){
    Node *f=x->fa,*ff=x->fa->fa;
    f->push_down();
    x->push_down();
    int c=x->d(),cc=f->d();
    f->setc(x->ch[!c],c);
    x->setc(f,!c);
    if(ff->ch[cc]==f) ff->setc(x,cc);
    else x->fa=ff;
    f->push_up();
}
inline void splay(Node * &root,Node * x,Node* goal){
    while(x->fa!=goal){
        if(x->fa->fa==goal) rotate(x);
        else {
            x->fa->fa->push_down();
            x->fa->push_down();
            x->push_down();
            bool f=x->fa->d();
            x->d() ==f ? rotate(x->fa):rotate(x);
            rotate(x);
        }
    }
    x->push_up();
    if(goal==null) root=x;
}
Node* get_kth(Node *r ,int k){
    Node *x=r;
    x->push_down();
    while(x->ch[0]->size+1!=k){
        if(k<x->ch[0]->size+1) x=x->ch[0];
        else {
            k-=x->ch[0]->size+1;
            x=x->ch[1];
        }
        x->push_down();
    }
    return x;
}
Node* get_next(Node *p){
    p->push_down();
    p=p->ch[1];
    p->push_down();
    while(p->ch[0]!=null){
        p=p->ch[0];
        p->push_down();
    }
    return p;
}
Node pool[MAXN],*tail;
Node *node[MAXN];
Node *root;
void build(Node* &x,int l,int r,Node *fa){
    if(l>r) return ;
    int mid=(l+r)/2;
    x=tail++;
    x->clear();
    x->fa=fa;
    node[mid]=x;
    build(x->ch[0],l,mid-1,x);
    build(x->ch[1],mid+1,r,x);
    x->push_up();
}
void init(int n){
    tail=pool;
    null=tail++;
    null->fa=null->ch[0]=null->ch[1]=null;
    null->size=0;null->rev=0;
    Node *p=tail++;
    p->clear();
    root=p;
    p=tail++;
    p->clear();
    root->setc(p,1);
    build(root->ch[1]->ch[0],1,n,root->ch[1]);
    root->ch[1]->push_up();
    root->push_up();
}
int a[MAXN],b[MAXN];
bool cmp(int i,int j){
    if(a[i]==a[j]) return i<j;
    else return a[i]<a[j];
}



int main(){
    int n;
    while(cin>>n&&n!=0){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=i;
        }
        init(n);
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n;i++){
            splay(root,node[b[i]],null);
            int sz=root->ch[0]->size;
            printf("%d",root->ch[0]->size);
            if(i==n) cout<<endl;
            else cout<<" ";
            splay(root,get_kth(root,i),null);
            splay(root,get_kth(root,sz+2),root);
            root->ch[1]->ch[0]->Update_Rev();
        }
    }
    return 0;
}
