#include <bits/stdc++.h>
using namespace std;
#define Max 1200050
int prime[Max];
void init()
{
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    for(int i=2;i<=Max;i++)
    {
        if(!prime[i])
        {
            for(int j=2*i;j<=Max;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
bool judge(int a)
{
    int len=0;
    int t=a;
    while(t>0)
    {
        t/=10;
        len++;
    }
    t=a;
    int tm[233];
    for(int i=1;i<=len;i++) {tm[i]=(t%10);t/=10;}
    for(int i=1;i<=len/2;i++)
    {
        if(tm[i]!=tm[len-i+1]) return false;
    }
    return true;
}
int main()
{
    int p,q;
    cin>>p>>q;
    init();
    int s1=0,s2=0;
    //for(int i=1;i<=1000;i++) if(judge(i)) cout<<i<<endl;
    int maxx=0;
    for(int i=1;i<=Max;i++)
    {
        if(judge(i)) s2+=p;
        if(!prime[i]) s1+=q;
        if(s2>=s1) maxx=max(maxx,i);
    }
    cout<<maxx;
    return 0;
}
