#include <bits/stdc++.h>
using namespace std;
int T;
int n;
char t[233];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        scanf("%s",t+1);
        for(int i=1;i<=n;i++)
        {
            if(t[i]=='*')
            {
                if(t[i-1]=='.') t[i-1]='%';
                if(t[i+1]=='.') t[i+1]='%';
            }
        }
        int cnt=0;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(t[i]=='.')
            {
                cnt++;
                if(cnt==3)
                {
                    res++;
                    cnt=0;
                }
            }
            else
            {
                if(cnt>0)
                {
                    res++;
                    cnt=0;
                }
            }
        }
        if(cnt>0) res++;
        cout<<res<<endl;
    }
    return 0;
}
