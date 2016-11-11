#include <iostream>
#include <stdio.h>
using namespace std;


int Q[1000001],P[1000001],a[1000001],q[1000001],p[1000001];
int n,k;


int head1,tail1,head2,tail2;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];

    head1=1,tail1=0;
  for(int i=0; i<k-1; i++)
  {
    while(head1<=tail1 && Q[tail1]>=a[i]) --tail1;
    Q[++tail1]=a[i];P[tail1]=i;
  }

  for(int i=k-1; i<n; i++)
  {
    while(head1<=tail1 && Q[tail1]>=a[i]) --tail1;
    Q[++tail1]=a[i]; P[tail1]=i;
    int y=head1;
    while(P[head1]<i-k+1) ++head1;
    if(i==n-1) printf("%d\n",Q[head1]);// cout<<Q[head1]<<endl;
    else printf("%d ",Q[head1]);
        //cout<<Q[head1]<<" ";
  }


    head2=1,tail2=0;
  for(int i=0;i<k-1;i++)
  {
    while(head2<=tail2&&q[tail2]<=a[i]) --tail2;
    q[++tail2]=a[i]; p[tail2]=i;
  }
  for(int i=k-1;i<n;i++)
  {
    while(head2<=tail2&&q[tail2]<=a[i]) --tail2;
    q[++tail2]=a[i]; p[tail2]=i;
    while(p[head2]<i-k+1) ++head2;
    if(i==n-1) printf("%d\n",q[head2]);
        //cout<<q[head2]<<endl;
    else printf("%d ",q[head2]);
    //cout<<q[head2]<<" ";
  }
    return 0;
}
