#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 100010
int fa[Max],ans[Max];
int T,n,m;
char t;
int a,b;

int ffind(int x){
    if(x!=fa[x]){
        int f=ffind(fa[x]);
        ans[x]^=ans[fa[x]];
        return fa[x]=f;
    }
    return x;
}

void Union(int x,int y){
    int f1=ffind(x);
    int f2=ffind(y);
    fa[f1]=f2;
    if(ans[x]==ans[y]) ans[f1]^=1;
    //ans[f1]=~(ans[x]^ans[y]);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        //cout<<n<<m;
        for(int i=1;i<=n;i++){
            fa[i]=i;
            ans[i]=0;
        }
        for(int i=1;i<=m;i++){
            //cin>>t>>a>>b;
            getchar();
            scanf("%c%d%d",&t,&a,&b);
            if(t=='D'){
                Union(a,b);
            }
            else {
                if(n==2)    //Ãÿ ‚Ω‚
                    printf("In different gangs.\n");
                else if(ffind(a)==ffind(b)){
                        if(ans[a]==ans[b])
                            printf("In the same gang.\n");
                        else
                            printf("In different gangs.\n");
                    }
                else
                        printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
