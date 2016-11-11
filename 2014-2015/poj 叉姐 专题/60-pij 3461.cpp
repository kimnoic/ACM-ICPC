#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int m,n;
int next[10010];
char s[10010];
char key[1000010];

void pre_kmp(){
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(j!=-1&&s[i]!=s[j]) j=next[j];
        next[++i]=++j;
    }
}
int KMP_Count(char x[],int m,char y[],int n){
    int i,j;
    int ans=0;
    pre_kmp();
    i=j=0;
    while(i<n){
        while(j!=-1 && y[i]!=x[j]) j=next[j];
        i++;j++;
        if(j>=m){
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int T;

int main(){
    cin>>T;
    while(T--){
        scanf("%s",s);
        scanf("%s",key);
        pre_kmp();
        m=strlen(s);
        n=strlen(key);
        cout<<KMP_Count(s,m,key,n)<<endl;
    }
    return 0;
}
