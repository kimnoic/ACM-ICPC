#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1000001;
int Q[maxn];
int P[maxn];
int a[maxn];
int n,k;

void minQ()
{
  int i;
  int head=1,tail=0;
  for(i=0; i<k-1; i++)//先入队
  {
    while(head<=tail && Q[tail]>=a[i])
      --tail;
    Q[++tail]=a[i];
    P[tail]=i;
  }

  for(; i<n; i++)//for执行时每次都要输出一个答案=-=
  {
    while(head<=tail && Q[tail]>=a[i])
      --tail;
    Q[++tail]=a[i];
    P[tail]=i;
    while(P[head]<i-k+1)//移动到合法位置
      head++;
    printf(i==n-1?"%d\n":"%d ",Q[head]);
  }
}
void maxQ()
{
  int i;
  int head=1,tail=0;
  for(i=0;i<k-1;i++)
  {
    while(head<=tail&&Q[tail]<=a[i])
      --tail;
    Q[++tail]=a[i];
    P[tail]=i;
  }
  for(;i<n;i++)
  {
    while(head<=tail&&Q[tail]<=a[i])
      --tail;
    Q[++tail]=a[i];
    P[tail]=i;
    while(P[head]<i-k+1)
      head++;
    printf(i==n-1?"%d\n":"%d ",Q[head]);
  }
}

int main()
{
  while(scanf("%d%d",&n,&k)==2)
  {
     for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
     minQ();
     maxQ();
  }
  return 0;
}
