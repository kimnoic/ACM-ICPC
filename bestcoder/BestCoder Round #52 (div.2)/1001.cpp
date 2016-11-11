#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x,y,w,n;
int now,has;
int main()
{
    while(~scanf("%d%d%d%d",&x,&y,&w,&n))
    {
        now=0;
        has=0;
        for(int i=1;i<n;i++)
        {
            now+=w;
            has+=w;
            if(has>x)
            {
                now=now-(has-x);
                now=now+y;
                has=0;
            }
        }
        cout<<now<<endl;
    }
    return 0;
}
