#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxm = 1<<21;
int f[maxm+10];
int m,n;
int base[21];
int t;

int dfs(int u)
{
    if(f[u]!=-1)return f[u];
    int flag = 0;
    for(int i=1;i<=20;i++)
    {
//        cout<<base[i]<<" "<<u<<" "<<(base[i]&u)<<endl;
        if((base[i]&u)!=0)
        {
            int j;
            for(j=i+1;j<=20;j++)
                if((base[j]&u)==0)break;
//            cout<<"i="<<i<<" j="<<j<<endl;
            if(j<=20)
            {
                if(dfs(u^base[i]^base[j])==0)
                    flag=1;
            }

        }
    }
    f[u]=flag;
//    ref(u);
//    print();
//    cout<<"f["<<u<<"]="<<f[u]<<endl;
    return f[u];
}
int main()
{
    memset(f,-1,sizeof(f));
    base[0]=1;
    for(int i=1;i<=20;i++)
        base[i]=base[i-1]*2;
    int tot=0;
    for(int i=20;i>=1;i--)
    {
        tot+=base[i];
        f[tot]=0;
    }

    scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&n);
            int w = 0;
            for(int j=1;j<=n;j++)
            {
                int k;
                scanf("%d",&k);
                w+=base[k];
            }
            if(f[w]==-1)
                f[w]=dfs(w);

            ans^=f[w];
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
