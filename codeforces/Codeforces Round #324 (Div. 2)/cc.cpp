#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
#define Max 100010
char a[Max],b[Max],c[Max];
int flag[Max];
int main()
{
    int  n,t;
    cin>>n>>t;
    int k=t;
    scanf("%s%s",a,b);
    t=n-t;
    int cnt=0;
    memset(flag,0,sizeof(flag));
    for (int i=0;i<n;i++)
    if (t>0)
    {
        if (a[i]==b[i])
        {
            t--;
            cnt++;
            c[i]=a[i];
            flag[i]=1;
        }
    }
    //cout<<t<<endl;
    if (t==0)
    {
        for (int i=0;i<n;i++)
            if (!flag[i])
            {
                for (j='a';j<='c';j++)
                    if (a[i]!=j&&b[i]!=j)
                        c[i]=j;
            }
        c[n]='\0';
        printf("%s\n",c);
    }
    else
    {
       if ((n-cnt)/2<t)
           cout<<-1<<endl;
        else
        {
            int cnta=0;
            int cntb=0;
            for (i=0;i<n;i++)
                if (cnta<t&&!flag[i])
                {
                    c[i]=a[i];
                    cnta++;
                    flag[i]=1;
                }
            for (int i=0;i<n;i++)
                if (cntb<t&&!flag[i])
                {
                    c[i]=b[i];
                    cntb++;
                    flag[i]=1;
                }
            for (int i=0;i<n;i++)
                if (!flag[i])
                {
                    for (j='a';j<='c';j++)
                        if (a[i]!=j&&b[i]!=j)
                            c[i]=j;
                }
            c[n]='\0';
            printf("%s\n",c);
        }
    }
    return 0;
}
