#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define Max 100010
char a[Max],b[Max];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s",a);
        scanf("%s",b);
        int lena=strlen(a);
        int lenb=strlen(b);
        if(lenb<lena)
        {
            printf("No\n");
            continue ;
        }
        if(a[0]!=b[0])
        {
            printf("No\n");
            continue ;
        }
        int cnt_b=1;
        for(int i=1;i<lenb;i++)
        {
            if(b[i]==b[0]) cnt_b++;
            else break;
        }
        int flag=1;

        if(cnt_b>=2)
        {
            for(int j=0;j<cnt_b;j++)
            {
                if(a[j]!=b[j])
                {
                    flag=0;
                    break;
                }
            }
        }
        cnt_b=1;
        if(!flag)
        {
            printf("No\n");
            continue;
        }
        int topa=0;
        int topb=0;
        while(1)
        {
            if(topa>=lena) break;
            if(topb>=lenb) break;
            if(a[topa]==b[topb])
            {
                topa++;
                topb++;
                continue ;
            }
            else
            {
                topb++;
            }

        }
        if(topa<lena) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
