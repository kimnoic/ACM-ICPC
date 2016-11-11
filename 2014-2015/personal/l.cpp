#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define rson l,m,rt*2
#define lson m+1,r,rt*2+1
#define Max 110
int mp[Max][Max];
int T;
int n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=m;j++){
                ans+=abs(mp[i][j]-mp[i-1][j]);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m+1;j++){
                ans+=abs(mp[i][j]-mp[i][j-1]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
