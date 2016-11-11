#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define Max 1000010
char s[Max];
int next[Max];
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
int main()
{
    while(~scanf("%s",s)){
        if(s[0]=='.') break;
        m=strlen(s);
        pre_kmp();
        //for(int i=1;i<=m;i++) cout<<next[i]<<" ";
        //cout<<endl;
        int ans=1;
        if(m%(m-next[m])==0&&next[m]!=0){
            ans=m/(m-next[m]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*aabaabaa*/
