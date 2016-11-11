#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 100001
#define M 2000000001
int k1[N],k2[N],k3[N];
int n,m,k,t2;
int x[N],y[N];
int ans1,ans2;
int row1[20000],row2[100000];
int col1[20000],row2[100000];
bool v1(int a,int b)
{
    ans1=0;ans2=0;
    for(int i=1;i<=k;i++)
    {
        if(k1[i]==a) {ans1++;}
        if(k1[i]==b) {ans2++;}
        if(ans1!=0&&ans2!=0) break;
    }
    if(ans1!=0&&ans2!=0) return true;
}
bool v2(int a,int b)
{
    ans1=0;ans2=0;
    for(int i=1;i<=k;i++)
    {
        if(k2[i]==a) ans1++;
        if(k2[i]==b) ans2++;
        if(ans1!=0&&ans2!=0) break;
    }
    if(ans1!=0&&ans2!=0) return true;
}
int main()
{
    int t;
    cin>>t;
    int a,b,c;
    int ca=1;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d",&k1[i],&k2[i],&k3[i]);
        }
        scanf("%d",&t2);
        printf("Case #%d:\n",ca);ca++;
        while(t2--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                if(v1(b,c))
                {
                    for(int i=1;i<=k&&(ans1>0||ans2>0);i++)
                    {
                        if(k1[i]==b) {k1[i]=c;ans1--;}
                        else if(k1[i]==c) {k1[i]=b;ans2--;}
                    }
                }
            }
            else if(a==2)
            {
                if(v2(b,c))
                {
                    for(int i=1;i<=k&&(ans1>0||ans2>0);i++)
                    {
                        if(k2[i]==b) {k2[i]=c;ans1--;}
                        else if(k2[i]==c) {k2[i]=b;ans2--;}
                    }
                }
            }
            else if(a==3)
            {
                int y=0;
                for(int i=1;i<=k;i++)
                {
                    if(k1[i]==b&&k2[i]==c)
                    {
                        printf("%d\n",k3[i]);
                        y++;
                        break;
                    }
                }
                if(y==0) printf("0",&n);
            }
        }
    }
    return 0;
}
