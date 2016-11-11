#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6+7;
int T;
int d,n;
int f[Max];int k[Max];
int sum;
long long res=0;
int main()
{
    cin>>T;int top=1;

    while(T--)
    {
        memset(f,0,sizeof(f));
        cin>>d>>n;
        sum=0;
        int t;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            sum+=t;
            sum%=d;
            f[sum]++;
        }
        f[0]++;
        res=0;
        for(int i=0;i<=d;i++)
        {
            long long t=f[i];
            if(t>=2)
            {
                res+=(t*(t-1))/2;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
