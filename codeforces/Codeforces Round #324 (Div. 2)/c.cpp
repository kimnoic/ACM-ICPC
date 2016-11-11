#include <bits/stdc++.h>
using namespace std;
#define Max 100010
char s1[Max],s2[Max];
char res[Max];
int vis[Max];
int n,t,cnt;
int main(){
    cin>>n>>t;
    cnt=0;
    memset(vis,0,sizeof(vis));
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]){
            vis[i]=1;
            cnt++;
        }
    }
    if(t<(n-cnt+1)/2){
        cout<<"-1";
    }
    else {
        int f=(n-cnt)%2;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(flag){
                    res[i]=s1[i];
                    flag=false;
                }
                else {
                    res[i]=s2[i];
                    flag=true;
                }
            }
        }
        if(f){
            //cout<<"asdf";
            for(int i=n-1;i>=0;i--){
                if(!vis[i]){
                    for(int j=97;j<=122;j++){
                        if((char)(j)!=s1[i]&&(char)(j)!=s2[i]){
                            res[i]=(char)(j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        //cout<<cnt<<endl;
        cnt=t-(n-cnt+1)/2;
        //cout<<res;
        //for(int i=0;i<n;i++) cout<<vis[i]<<endl;
        for(int i=0;i<n;i++){
            if(cnt){
                    if(vis[i]){
                    for(int j=97;j<=122;j++){
                        if((char)(j)!=s1[i]&&(char)(j)!=s2[i]){
                            res[i]=(char)(j);
                            //cout<<res<<endl;
                            break;
                        }
                    }
                    cnt--;

                }
            }
            else {
                if(vis[i])
                    res[i]=s1[i];
            }
        }
    }
    cout<<res;
    return 0;
}
