#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int s;
int coin[233];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>s;
        for(int i=1;i<=n;i++) cin>>coin[i];
        sort(coin+1,coin+n+1);
        int len=pow(2,n);
        int res=0;
        for(int i=0;i<len;i++)
        {
            int k=i;
            int minn=1000;
            int cnt=0;
            int sum=0;
            int q[12];
            for(int j=1;j<=n;j++)
            {
                int f=k%2;
                //cout<<f;
                q[j]=f;
                k/=2;
                if(f)
                {
                    sum+=coin[j];
                    //cout<<" "<<coin[i];
                    cnt++;
                    minn=min(minn,coin[j]);
                }
            }
            int top=1;
            while(top<=n)
            {
                if(q[top])
                {
                    if(sum-coin[top]>=s)
                    {
                        sum-=coin[top];
                        q[top]=0;
                        cnt--;
                        top++;
                    }
                    else break;
                }
                else top++;
            }
            if(sum>=s)
            res=max(res,cnt);
        }
        cout<<res<<endl;
    }
    return 0;
}
