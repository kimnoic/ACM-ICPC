#include <iostream>
#include <string.h>
#define Max 600
using namespace std;

long long s1[Max],s2[Max];
long long sum[Max][Max];
long long  max(long long a,long long b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int t;
    cin>>t;
    int a1 ;int b1;
    while (t--)
    {
        cin>>a1;
        for(int i=1;i<=a1;i++) cin>>s1[i];
        cin>>b1;
        for(int i=1;i<=b1;i++) cin>>s2[i];
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=a1;i++)
        {
            for(int j=1;j<=b1;j++)
            {
                if(s1[i-1]==s2[j-1]) {sum[i][j]+=sum[i-1][j-1]+1;}//cout<<i+1<<" "<<j+1<<endl;}
                else sum[i][j]=max(sum[i-1][j],sum[i][j-1]);
            }
        }
        cout<<sum[a1][b1]<<endl;
    }
    return 0;
}
