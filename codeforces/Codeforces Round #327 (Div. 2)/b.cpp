#include <bits/stdc++.h>
using namespace std;
int n,m;
#define Max 200010
char t[Max];
char mp[300];
int vis[300];
int main(){
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    scanf("%s",t);
    for(int i=97;i<=122;i++){
        mp[i]=(char)i;
    }
    for(int i=1;i<=m;i++){
        char a,b;
        scanf(" %c %c",&a,&b);
        for(int j=97;j<=122;j++){
            if(mp[j]==a){
                mp[j]=b;
            }
            else if(mp[j]==b){
                mp[j]=a;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(mp[t[i]]){
            printf("%c",mp[t[i]]);
        }
        else printf("%c",t[i]);
    }
    return 0;
}
//97 122
