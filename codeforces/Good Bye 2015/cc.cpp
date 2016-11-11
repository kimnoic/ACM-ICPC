#include<bits/stdc++.h>
using namespace std;
#define Max 505
int s[Max][Max],ff[Max][Max];
int fx,fy,tx,ty,ans,m,n;
char cccc;
int q;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            scanf(" %c",&cccc);
            if(cccc=='.')
                s[i][j]=1;
            else
                s[i][j]=0;
        }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ff[i][j]=ff[i][j-1]+ff[i-1][j]-ff[i-1][j-1];
            int cnt=0;
            if(s[i][j]&&s[i-1][j])
                cnt++;
            if(s[i][j]&&s[i][j-1])
                cnt++;
            ff[i][j]+=cnt;
        }
    }

    int ans;
    cin>>q;
    int cnt=1;
    for(int j=1;j<=q;j++){
        scanf("%d%d%d%d",&fx,&fy,&tx,&ty);
        ans=ff[tx][ty]-ff[tx][fy-1]-ff[fx-1][ty]+ff[fx-1][fy-1];
        for(int i=fy;i<=ty;i++)
            if(s[fx][i]&&s[fx-1][i])
                ans--;
        for(int i=fx;i<=tx;i++)
            if(s[i][fy]&&s[i][fy-1])
                ans--;
        if(cnt==j){
            printf("%d\n",ans);
            cnt++;
        }
    }
    return 0;
}
