#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define Max 2000010
long long f[2][Max];
int T;
int n,m;
int main(){
    cin>>T; int _case=0;
    while(T--){
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        f[0][0]=1;
        int t;
        int k=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t);

            for(int j=0;j<Max;j++){
                if((j^t)<Max)
                    f[k^1][j^t]=f[k][j^t]+f[k][j];
            }k^=1;
        }
        long long ans=0;

        for(int i=m;i<Max;i++){
                //cout<<i<<" "<<f[k][i]<<endl;
                //cout<<ans<<endl;
            ans+=f[k][i];
            //cout<<ans<<endl;
        }
        cout<<"Case #"<<++_case<<": "<<ans<<endl;
    }
    return 0;
}
