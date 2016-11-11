#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <time.h>
using namespace std;
#define Max 1000010
int nnext[Max];
char c[Max];
int T;
void get_next(char x[],int m){
    int i,j;
    j=nnext[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1 && x[i]!=x[j]) j=nnext[j];
        nnext[++i]=++j;
    }
}
int ans=0;
void init(){
    ans=0;
    scanf("%s",c);
    get_next(c,strlen(c));
}
bool f[Max];
void solve(){
    memset(f,0,sizeof(f));
    int len=strlen(c);
    int p=len;
    while(p>0){
        if(2*p<=len) f[p]=1;
        p=nnext[p];
    }
    for(int i=len-1;i>1;i--){
        p=i;
        while(p>0){
            if(2*p<=i&&f[p]&&(p+i)<=len) {
                ans=max(p,ans);
                break;
            }
            p=nnext[p];
        }
    }
}
int main(){
    cin>>T;
    while(T--){
        init();
        solve();
        cout<<ans<<endl;
    }
    return 0;
}
