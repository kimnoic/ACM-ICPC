#include <bits/stdc++.h>
#define Max 1010
char t[Max],tmp[3];
int n;
int mp[30][30];
using namespace std;
int main(){
    cin>>n;
    memset(mp,0,sizeof(mp));
    while(n--){
        scanf("%s",t);
        int len=strlen(t);
        int flag=0;
        tmp[1]=t[0];
        for(int i=1;i<len;i++){
            if(!flag){
                if(t[i]!=tmp[1]){
                    tmp[2]=t[i];
                    flag=1;
                }
            }
            else if(t[i]!=tmp[1]&&t[i]!=tmp[2]){
                flag=2;
                break;
            }
        }
        if(flag==0){
            mp[tmp[1]-'a'+1][tmp[1]-'a'+1]+=len;
        }
        else if(flag==1){
            if(tmp[1]>tmp[2]){
                swap(tmp[1],tmp[2]);
            }
            mp[tmp[1]-'a'+1][tmp[2]-'a'+1]+=len;
        }
    }
    int res=0;
    for(int i=1;i<=26;i++){
        for(int j=i+1;j<=26;j++){
            res=max(res,mp[i][j]+mp[i][i]+mp[j][j]);
        }
    }
    cout<<res;
    return 0;
}
