#include <bits/stdc++.h>
using namespace std;
#define Max 300010
int n,m;
char t[Max];
int main()
{
    cin>>n>>m;
    scanf("%s",t+1);
    int res=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]=='.') flag++;
        else flag=0;
        if(flag>=2) res++;
    }
    char tt;int b;
    for(int i=1;i<=m;i++)
    {
        cin>>b;cin>>tt;

        if(tt=='.')
        {
            if(t[b]!='.')
            {
                if(t[b-1]=='.') res++;
                if(t[b+1]=='.') res++;
            }
            t[b]='.';
        }
        else
        {
            if(t[b]=='.')
            {
                if(t[b-1]=='.') res--;
                if(t[b+1]=='.') res--;
            }
            t[b]='a';
        }
        printf("%d\n",res);
    }
    return 0;
}
