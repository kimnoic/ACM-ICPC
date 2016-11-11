#include <iostream>
#include <stdio.h>
using namespace std;
#define Max 1000005
#define Maxx 3000005
int a[Max];
int b[Maxx];
int ans;
long long judge(int a)
{
    if(a==1) return 2;
    else return judge(a-1)*2;
}
void judge()
{

}
int main()
{
    int t;
    a[0]=4;
    cin>>t;
    int n;
    int _case=1;
    while(t--)
    {
        cin>>n; ans=1;
        if(n==0)
        {
            printf("Case #%d: 0\n",_case);_case++;continue;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0||a[i]==a[i-1]) continue;
            if(a[i]+a[i-1]<=3)
                ans++;
        }
        if(n==1&&a[1]==0)
            printf("Case #%d: 1\n",_case);
        else printf("Case #%d: %lld\n",_case,judge(ans));
        _case++;
    }
    return 0;
}
