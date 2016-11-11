#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 1000010
int next[Max];
char s[Max];
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
int main(){
    int _case=0;
    while(cin>>m){if(m==0) break;
        cout<<"Test case #"<<++_case<<endl;

        cin>>s;
        pre_kmp();
        for(int i=2;i<=m;i++){
            if(i%(i-next[i])==0&&next[i]!=0){
                cout<<i<<" "<<i/(i-next[i])<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
