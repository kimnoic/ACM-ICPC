#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define Max 100010
struct pt{
    int val,p;
}p[Max];
bool cmp(pt a,pt b){
    return a.val>b.val;
}
struct Node {
    Node *ch[2],*fa;
    int size;
    int val;
    Node (){
        ch[0]=ch[1]=fa=NULL;
    }
    inline void push_up(){
        if(this==NULL) return ;
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
        ch[0]=ch[1]=fa=NULL;
    }
    inline bool isroot(){
        return fa==NULL||this!=fa->ch[0]&&this!=fa->ch[1];
    }
};

inline void rotate(Node *x){
    Node *f=x->fa,*ff=x->fa->fa;
    int c=x->d(),cc=f->d();
    f->setc(x->ch[!c],c);
    x->setc(f,!c);
    if(ff->ch[cc]==f) ff->setc(x,cc);
    else x->fa=ff;
    f->push_up();
}
inline void splay(Node* &root,Node *x,Node *goal){
    while(x->fa!=goal){
        if(x->fa->fa==goal) rotate(x);
        else {
            bool f=x->fa->d();
            x->d()==f?rotate(x->fa):rotate(x);
            rotate(x);
        }
    }
    x->push_up();
    if(goal==NULL) root=x;
}
Node *get_kth(Node *r,int k){
    Node *x=r;
    while(x->ch[0]->size+1!=k){
        if(k<x->ch[0]->size+1) x=x->ch[0];
        else {
            k-=x->ch[0]->size+1;
            x=x->ch[1];
        }
    }
    return x;
}
inline void print(Node *r){
    if(r->ch[0]){
        print(r->ch[0]);
    }
    printf("%d ",r->val);
    if(r->ch[1]){
        print(r->ch[1]);
    }
}
Node *root;
int T,n;
int main(){
    scanf("%d",&T);
    int _case=0;
    while(T--){
        scanf("%d",&n);
        //r.clear();
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i].val,&p[i].p);
        }
        printf("Case #%d: ",++_case);
        sort(p+1,p+n+1,cmp);
        int flag=0;
        //Init();
        for(int i=1;i<=n;i++){
            if(p[i].p>i-1) {
                flag=1;
                break;
            }
            int t=i-1-p[i].p;
            if(p[i].p>t){
                p[i].p=t
                ;
            }
        }
        if(!flag){
            root->clear();
            Node *tmp;
            tmp->val=p[1].val;
            for(int i=2;i<=n;i++){
                Node *tem=get_kth(root,p[i].p);
                splay(root,tem,root);
                Node *ll=get_kth(root,i);
                splay(root,ll,tem->ch[1]);
                Node *tm;
                tm->val=p[i].val;
                root->ch[1]->ch[0]=tm;
            }
        }
        if(flag){
            printf("impossible\n");
        }
        else {
                print(root);
        }
        printf("\n");
    }
    return 0;
}





















