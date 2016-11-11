#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char a[101],b[101];
int map[101][101];
int chart[5][5]={ {5,-1,-2,-1,-3},
                  {-1,5,-3,-2,-4},
                  {-2,-3,5,-2,-2},
                  {-1,-2,-2,5,-1},
                  {-3,-4,-2,-1,10}};
int idx(char x);
int max(int a,int b);

int main()
{
  int T,i,j,ans,alen,blen,tmp;
  scanf("%d",&T);

     do
     {
        scanf("%d%s",&alen,a);
        scanf("%d%s",&blen,b);

        memset(map,0,sizeof(map));

        for(i = 1 ; i <= alen ; ++i)
        {map[i][0] = map[i-1][0] + chart[idx(a[i-1])][idx('-')] ;cout<<map[i][0];} cout<<endl;

        for(i = 1 ; i <= blen ; ++i)
        map[0][i] = map[0][i-1] + chart[idx('-')][idx(b[i-1])];

         for(i = 1 ; i <= alen ; ++i)
              for(j = 1 ; j <= blen ; ++j)
              {
                   tmp = max(map[i-1][j-1]+chart[idx(a[i-1])][idx(b[j-1])],
                    map[i-1][j]+chart[idx(a[i-1])][idx('-')]) ;
                   map[i][j] =max(tmp,map[i][j-1]+chart[idx('-')][idx(b[j-1])]);
              }

       printf("%d\n",map[alen][blen]);

     }while(--T);
  return 0;
}


int idx(char x)
{
     int ans;
         switch(x)
         {
           case 'A':ans = 0;break;
           case 'C':ans = 1;break;
           case 'G':ans = 2;break;
           case 'T':ans = 3;break;
           default: ans = 4;break;
         };
     return ans;
}

int max(int a,int b)
{
  return a>b? a:b;
}
/*
2
7 AGTGATG
5 GTTAG
-3-5-6-8-11-12-14
14
7 AGCTATT
9 AGCTTTAAA
-3-5-9-10-13-14-15
21
*/
