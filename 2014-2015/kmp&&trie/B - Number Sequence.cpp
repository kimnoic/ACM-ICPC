#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void prekmp(int *k,int n,int *rule)
{
    int i=0,j=-1;
    rule[0]=j;
    while (i<n)
    {
        while(j!=-1&&k[j]!=k[i]) j=rule[j];
        i++;j++;
        if(j>=n) rule[i]=rule[i-1];
        else rule[i]=j;
    }
}

int sum=0;
int temp;

void kmp(int *k, int m, int *d, int n)
{
    int rule[10005];
    prekmp(k,m,rule);
    int i=0, j=0;
    while(i<n)
        {
        while(j!=-1 && k[j] != d[i]){
            j = rule[j];
        }
        i++,j++;
        if(j==m)
        {
            temp=i;
            //cout<<"i"<<i;
            return ;
            j=rule[j];
        }
    }
}
int s1[10001],s2[1000001];
int main()
{
    int t;
    cin>>t;
    int a;int b;
    while (t--)
    {
        temp=-1;
        cin>>a>>b;
        for(int i=0;i<a;i++) scanf("%d",&s2[i]);
        for(int i=0;i<b;i++) scanf("%d",&s1[i]);

        kmp(s1,b,s2,a);
        if(temp==-1) cout<<temp<<endl;
           else cout<<temp-b+1<<endl;
    }
    return 0;
}
