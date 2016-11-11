#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[400010];
int next[400000];
int m;
void pre_kmp(){
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1&&s[i]!=s[j]) j=next[j];
        next[++i]=++j;
    }
}
int ans[400000];
int main(){
    while(cin>>s){
        m=strlen(s);
        pre_kmp();
        int len=strlen(s);

        int cnt=0;
        while(len!=0){
            ans[++cnt]=len;
            len=next[len];
        }
        for(int i=cnt;i>0;i--){
            if(i==1) printf("%d\n",ans[i]);
            else printf("%d ",ans[i]);
        }
    }
    return 0;
}
