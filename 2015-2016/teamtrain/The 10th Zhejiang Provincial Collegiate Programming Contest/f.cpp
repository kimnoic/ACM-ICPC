#include <bits/stdc++.h>

using namespace std;
#define Max 233
int mp[Max][Max];

int main(){

    int t,n,m,k,p,cun,countt,a,b,flag;

    scanf("%d",&t);
    while(t--){
        memset(mp,0,sizeof(mp));
countt=0;
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            mp[a+1][b+1]=1;
            mp[b+1][a+1]=1;
        }
        int change=1;
        while(change){
        change=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                flag=0;
                cun=0;
                if (j==i) continue;
                if (mp[i][j]==1) continue;
                for (int p=1;p<=n;p++){
                    if (mp[i][p]&&mp[j][p])
                        cun++;
                    if (cun>=k) {flag=1;mp[i][j]=1;mp[j][i]=1;break;}
                }
                if (flag==1){
                    countt++;
                 change=1;
                }
            }
        }
        }

        printf("%d\n",countt);

    }


    return 0;

}
