#include <string.h>
#include <iostream>
#define Max 1000001
using namespace std;
string s;
int l,r,n,ll;
struct node
{
    int l,r,a,b,ans;
}tree[4*Max];
int min(int a,int b)
{
    if(a>b) return b;
    else return a;
}
int mid(int a,int b)
{
    return (a+b)>>1;
}
void build(int step,int l,int r)
{
    tree[step].l=l; tree[step].r=r;
    if (l==r)
    {   tree[step].ans=0;
        if (s[l-1]=='(')
        {
            tree[step].a=1,tree[step].b=0;
        }
        else
        {
            tree[step].a=0,tree[step].b=1;
        }
        return;
    }
    build(2*step,l,mid(l,r));
    build(2*step+1,mid(l,r)+1,r);
    int temp=min(tree[2*step].a,tree[2*step+1].b);
    tree[step].ans=temp*2+tree[2*step].ans+tree[2*step+1].ans;
    tree[step].a=tree[2*step].a+tree[2*step+1].a-temp;
    tree[step].b=tree[2*step].b+tree[2*step+1].b-temp;
}
int query(int step,int l,int r,int &a,int &b)
{
    if (tree[step].l==l&&tree[step].r==r)
    {
        a+=tree[step].a;
        b+=tree[step].b;
        return tree[step].ans;
    }
    if (tree[2*step].r>=r)
        return query(2*step,l,r,a,b);
    else if (tree[2*step+1].l<=l)
        return query(2*step+1,l,r,a,b);
        else
    {
        int sum=0;
        int t=a;
        sum+=query(2*step,l,tree[2*step].r,a,b);
        int a2=a-t;
        int b2=b;
        sum+=query(2*step+1,tree[2*step+1].l,r,a,b);
        int b3=b-b2;
        int c=min(a2,b3);
        sum+=c*2;
        a-=c; b-=c;
        return sum;
    }
}
int main()
{
    cin>>s;
    ll=s.size();
    build(1,1,ll);
    cin>>n;
    int t1=0;
    int t2=0;
    for (int i=0;i<n;i++)
    {
        t1=0;
        t2=0;
        cin>>l>>r;
        cout<<query(1,l,r,t1,t2)<<endl;
    }
    return 0;
}
