#include <iostream>
#include <stdio.h>
using namespace std;

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int n,x,y,z,t,k;
long long ans;
void sum(int a,int b)
{
    ans=y*(a-1)*a/2+k*(k-1)*a*y*b/2+k*(a*y+x)*(n-a-b);
}
int main()
{
    int t;
    cin>>t;
    long long maxx;
    int u=1;
    for(int r=1;r<=t;r++)
    {
        maxx=0;
        scanf("%d%d%d%d%d",&n,&x,&y,&z,&t);
                printf("Case #%d: ",u);u++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;i+j<=n;j++)
            {
                k=j*z+t;
                sum(i,j);
                if(ans>maxx)
                {
                    maxx=ans;
                }
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
