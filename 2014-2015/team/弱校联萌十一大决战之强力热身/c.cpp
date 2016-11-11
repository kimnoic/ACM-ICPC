#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 2000010
char a[Max],b[Max];
int vis[Max];
char q[Max];
int kmpNext[Max];

void preKMP(int m){
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1 && a[i]!=a[j]) j=kmpNext[j];
        if(a[++i]==a[++j]) kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}

int main(){
    while(~scanf("%s %s",a,b)){
        int len = strlen(a);
        preKMP(len);
        int top=0;
        int top_a=0;
        for(int i=0;i<strlen(b);i++){
            if(b[i]==a[top_a]){
                q[++top]=b[i];
                top_a++;
                vis[top]=top_a;
                if(top_a==len){
                    top-=top_a;
                    if(top<0) top=0;
                    top_a=vis[top];
                }
            }
            else {
                //cout<<pos<<endl;
                /*
                if(pos-1>0)
                top_a=kmpNext[pos-1]+2;
                else top_a=0;*/

                //============
                //top_a-=(kmpNext[top_a-1]+2);
                //cout<<i<<" "<<top_a<<endl;
                while(top_a>0&&a[top_a]!=b[i]){
                    //cout<<" "<<i<<" "<<top_a<<endl;
                    //===========
                    top_a=top_a-(kmpNext[top_a-1]+2);//dis
                    if(top_a<0) top_a=0;
                }
                //cout<<i<<" top_a "<<top_a<<endl;

                if(a[top_a]==b[i])
                top_a++;
                else top_a=0;
                q[++top]=b[i];vis[top]=top_a;
                //cout<<i<<" "<<top_a<<endl;
            }
            /*
            cout<<"i "<<i<<" "<<top_a<<endl;
            for(int i=1;i<=top;i++){
                cout<<vis[i]<<" ";
            }
            cout<<endl;*/
        }

        for(int i=1;i<=top;i++){
            printf("%c",q[i]);
        }
        printf("\n");
    }
    return 0;
}
