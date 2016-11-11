#include <bits/stdc++.h>
using namespace std;
int h,w;
#define Max 505
char mp[Max][Max];
int mmp[Max][Max];
int main(){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf(" %c",&mp[i][j]);
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            mmp[i][j]=mmp[i-1][j]+mmp[i][j-1]-mmp[i-1][j-1];
            int cnt=0;
            if(mp[i][j]=='#') continue;
            if(mp[i][j]==mp[i-1][j]) cnt++;
            if(mp[i][j]==mp[i][j-1]) cnt++;
            mmp[i][j]+=cnt;
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<mmp[i][j]<<" ";
        }
        cout<<endl;
    }
    int q;
    cin>>q;
    int r1,c1,r2,c2;
    for(int i=1;i<=q;i++){
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        printf("%d\n",mmp[r2][c2]-mmp[r1-1][c2]-mmp[r2][c1-1]+mmp[r1-1][c1-1]);
    }
    return 0;
}
