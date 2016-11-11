#include <ext/rope>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
using namespace __gnu_cxx;
const int maxn=1e4+10;
int a[10010];

char st[maxn];
int m;
char key[maxn];
char clea[maxn];
int T;
int pos,tol,lastp;
bool flag=0;
int flag_c;

int main(){
    cin>>T;
    while(T--){
        cin>>m;
        cin>>key;
        flag=1;
        pos=0;
        tol=0;
        flag_c=0;
        rope<char> *his[maxn];
        int len=sizeof(key);
        for(int i=0;i<len;i++){
            cout<<i<<endl;
            if(i!=0)
            his[i]=new rope<char>(*his[i-1]);
            if(key[i]>='a'){
                flag_c=0;
                if(flag){
                    his[i]->insert(pos,key[i]);
                    pos++;
                    tol++;
                }
                else {
                    his[i]->insert(pos,key[i]);
                    pos++;
                    his[i]->erase(pos,1);

                }
            }
            else if(key[i]=='L'){
                pos=0;
            }
            else if(key[i]=='R'){
                pos=tol;
            }
            else if(key[i]=='S'){
                flag^=1;
                flag_c=0;
            }
            else if(key[i]=='D'&&pos!=0){
                his[i]->erase(pos-1,1);
                pos--;
                tol++;
            }
            else if(key[i]=='C'){
                if(flag_c==0){
                    lastp=pos;
                    flag_c=1;
                }
                else {
                    if(pos!=lastp){
                        int tmax=max(pos,lastp);
                        int tmin=min(pos,lastp);
                        cout<<his[i]->substr(tmin,tmax-tmin);
                        flag_c=3;
                    }
                }
            }
            else if(key[i]=='V'&&flag_c==3){
                int l=strlen(st);
                if(flag){
                    for(int j=0;j<l;j++){
                        tol++;
                        his[j]->insert(pos,st[j]);
                        pos++;
                    }
                }
                else {
                    for(int j=0;j<l;j++){
                        his[j]->erase(pos,1);
                        his[j]->insert(pos-1,st[j]);
                    }
                }
            }

        }
    }
    return 0;
}
/*
x->at(10);
x[10];
x->push_back(x)     // 在末尾添加x
x->insert(pos,x)    // 在pos插入x
x->erase(pos,x)     // 从pos开始删除x个
x->replace(pos,x)   // 从pos开始换成x
x->substr(pos,x)    // 提取pos开始x个
*/
