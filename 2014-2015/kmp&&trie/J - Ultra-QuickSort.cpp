#include<iostream>

using namespace std;

long long sum;
int n,a[500001];
int t[500001];

void un(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    for(;i<=m&&j<=r;k++)
    {
        if(a[i]<=a[j])
            t[k]=a[i++];
        else {
        t[k]=a[j++];
        sum+=(m-i+1);}
    }
    while(i<=m)
        t[k++]=a[i++];
    while(j<=r)
    t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)
    a[i]=t[k++];
}

void sort(int a[],int l,int r)
{
    if(l==r)
        a[l]=a[r];
    else
    {
        int m=(l+r)>>1;
        sort(a,l,m);  sort(a,m+1,r);
        un(a,l,m,r);
    }
}
int main()
{
    while(cin>>n&&n!=0)
        {
            sum=0;
            for(int i=1;i<=n;i++) cin>>a[i];
            sort(a,1,n);
            cout<<sum<<endl;
        }
        return 0;
}
