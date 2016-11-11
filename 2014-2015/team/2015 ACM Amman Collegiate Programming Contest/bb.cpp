#include <bits/stdc++.h>
using namespace std;
int T;
int n;
char t[2333];
int rl[2333],rw[2333],pl[2333],pw[2333],sl[2333],sw[2333];
void init()
{
    memset(rl,0,sizeof(rl));
    memset(rw,0,sizeof(rw));
    memset(sl,0,sizeof(sl));
    memset(sw,0,sizeof(sw));
    memset(pl,0,sizeof(pl));
    memset(pw,0,sizeof(pw));
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        scanf("%s",t+1);
        init();
        char tm;
        for(int i=1;i<=n;i++)
        {
            rl[i]=rl[i-1];sl[i]=sl[i-1];sw[i]=sw[i-1];
            rw[i]=rw[i-1];pl[i]=pl[i-1];pw[i]=pw[i-1];
            if(t[i]=='R')
            {
                pw[i]++;sl[i]++;
            }
            else if(t[i]=='S')
            {
                rw[i]++;pl[i]++;
            }
            else
            {
                sw[i]++;rl[i]++;
            }
        }
        int res=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;i+j<=n;j++)
            {
                int k=n-j-i;

                if(rw[i]+pw[i+j]-pw[i]+sw[n]-sw[n-k]>rl[i]+pl[i+j]-pl[i]+sl[n]-sl[n-k]) {res++;}

            }
        }
        cout<<res<<endl;
    }
    return 0;
}
