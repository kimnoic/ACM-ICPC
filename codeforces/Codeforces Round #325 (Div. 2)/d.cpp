#include <bits/stdc++.h>

using namespace std;
char ss[4][123];
bool f[4][123];
int m,n,k,t;
int w;
int main(){
    scanf("%d",&t);
    while (t--){
        cin>>n>>k;
        int len=(n/3)*3+3;
        for (int i=1;i<=3;i++)
            scanf("%s",ss[i]);
        w++;
        for (int i=n;i<=n+10;i++)
            ss[1][i]=ss[2][i]=ss[3][i]='.';
        memset(f,false,sizeof(f));
        for (int i=1;i<=3;i++)
            if (ss[i][0]=='s')
                f[i][0]=true;
        for (int i=0;i<=len;i+=3){
            w++;
            if (ss[1][i+1]=='.'&&f[1][i])
            {
                if (ss[1][i+3]=='.'&&ss[1][i+1]=='.'&&ss[1][i+2]=='.') f[1][i+3]=true;
                if (ss[2][i+3]=='.'&&ss[2][i+1]=='.'&&ss[2][i+2]=='.') f[2][i+3]=true;
            }
            if (ss[2][i+1]=='.'&&f[2][i])
            {
                if (ss[2][i+3]=='.'&&ss[2][i+1]=='.'&&ss[2][i+2]=='.') f[2][i+3]=true;
                if (ss[1][i+3]=='.'&&ss[1][i+1]=='.'&&ss[1][i+2]=='.') f[1][i+3]=true;

                if (ss[3][i+3]=='.'&&ss[3][i+1]=='.'&&ss[3][i+2]=='.') f[3][i+3]=true;
            }
            if (ss[3][i+1]=='.'&&f[3][i])
            {
                if (ss[3][i+3]=='.'&&ss[3][i+1]=='.'&&ss[3][i+2]=='.') f[3][i+3]=true;
                if (ss[2][i+3]=='.'&&ss[2][i+1]=='.'&&ss[2][i+2]=='.') f[2][i+3]=true;
            }
        }
        if (f[3][len])
            printf("YES\n");
        else if(f[2][len]||f[1][len])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
