#include <cstdio>
#include <algorithm>
#include <iostream>

#define LL long long
using namespace std;

LL a[3000][3000],fl[3000][3000],fr[3000][3000],maxx=0,maxi,maxj,minn=0,mini,minj;
int n;

int main()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)scanf("%I64d",&a[i][j]);
     for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)fl[i][j]=fl[i-1][j-1]+a[i][j];
     for(int i=n-1;i>=1;i--)
          for(int j=n-1;j>=1;j--)fl[i][j]=fl[i+1][j+1];
     for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)fr[i][j]=fr[i-1][j+1]+a[i][j];
     for(int i=n-1;i>=1;i--)
          for(int j=n;j>=2;j--)fr[i][j]=fr[i+1][j-1];

     for(int i=1;i<=n;i++)
		{
          for(int j=1;j<=n;j++)
          {
               if((i+j)%2==0)
               {
                    if(maxx<=fl[i][j]+fr[i][j]-a[i][j])
                    {
                         maxx=fl[i][j]+fr[i][j]-a[i][j];
                         maxi=i;
                         maxj=j;
                    }
               }else{
                    if(minn<=fl[i][j]+fr[i][j]-a[i][j])
                    {
                         minn=fl[i][j]+fr[i][j]-a[i][j];
                         mini=i;
                         minj=j;
                    }
               }
		  }
     }
     cout<<maxx+minn<<endl;
     printf("%I64d %I64d %I64d %I64d\n",maxi,maxj,mini,minj);
     return 0;
}
