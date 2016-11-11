#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int a,b;
int main()
{
    int Case=0;
    while(scanf("%d %d",&a,&b))
    {
        if(a==-1&&b==-1) break;int s1=0,s2=0;
        int top=0;
        int len=0;
        int t=a;
        len=(int)log10(a)+1;
        t=a;
        for(int i=1;i<=len;i++)
        {
            if((len-i+1)%2==1) s1+=t%10;
            else s2+=t%10;
            t/=10;
            top++;
        }
        while(b--)
        {
            int sum=0;
            sum=s1+s2;
            //sum%=11;

            int len=(int)(log10(sum))+1;

            int k=top+len;
            for(int i=1;i<=len&&sum>0;i++)
            {
                if(k%2==1) s1+=sum%10;
                else s2+=sum%10;
                k--;
                sum/=10;
            }
            top+=len;
            //s1%=11;
            //s2%=11;

        }

        int res=s2-s1;
        //cout<<s1<<" "<<s2<<endl;
        if(res%11==0) printf("Case #%d: Yes\n",++Case);
        else printf("Case #%d: No\n",++Case);
        //cout<<"Case #"<<++Case<<": No"<<endl;
    }
    return 0;
}
