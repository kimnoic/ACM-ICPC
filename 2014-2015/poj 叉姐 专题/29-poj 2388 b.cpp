#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
void Swap( int &a, int &b )
{
  int hold = b;

  b = a;
  a = hold;
}

void Qsort( int a[], int left, int right )
{
  int i, j;
  int mid;
  int m;

  if( left < right )
  {
     i = left - 1;
     j = right;
     mid = (left+right)/2;
     m = a[mid];
     Swap( a[mid], a[right] );
     for( ; ; )
     {
         while( a[++i] < m ) {}
         while( a[--j] > m ) {}
         if( i < j )
             Swap( a[i], a[j] );
         else break;
     }
     Swap( a[i], a[right] );
     Qsort( a, left, i-1 );
     Qsort( a, i+1, right );
  }
}
int main()
{
    int n,i;
    int a[10002];

    scanf("%d",&n);
    for(i = 0; i < n; i++)
       scanf("%d",&a[i]);
    Qsort( a, 0, n-1 );
    printf("%d\n",a[(n-1)/2]);
    return 0;
}
