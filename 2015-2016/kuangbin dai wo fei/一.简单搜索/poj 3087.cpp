#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 500
char s1[Max],s2[Max],s[Max],g[Max];
int T;
int c;
map<string,int>mp;
int main(){
    cin>>T;
    int _case=0;

    while(T--){
        cin>>c;
        scanf("%s %s",s1,s2);
        scanf("%s",g);
        mp.clear();
        int flag=0;
        int cnt=0;
        while(1){
            cnt++;
            s[0]='\0';

            int top=0;
            for(int i=0;i<c;i++){
                s[top++]=s2[i];
                s[top++]=s1[i];
            }
            s[top]='\0';
            if(strcmp(s,g)==0){
                flag=1;
                break;
            }
            else if(mp[s]&&strcmp(s,g)){
                flag=-1;
                break;
            }
            mp[s]=1;
            for(int i=0;i<c;i++)s1[i]=s[i];
            for(int i=c;i<top;i++) s2[i-c]=s[i];
        }
        if(flag==1){
            cout<<++_case<<" "<<cnt<<endl;
        }
        else if(flag==-1){
            cout<<++_case<<" -1"<<endl;
        }
    }
    return 0;
}
