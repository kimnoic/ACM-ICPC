#include <iostream>

using namespace std;

struct line
{
    int left ,right ,num;
}a[16];

void insert(int s,int t,int step)
{
    if(s==a[step].left&&t==a[step].right)
    {
        a[step].num++;
        return ;
    }
    if(a[step].left==a[step].right) return ;
    int mid=(a[step].left+a[step].right)/2;
    if(mid>=t) insert(s,t,step*2);
    else if(mid<s) insert(s,t,step*2+1);
    else
    {
        insert(s,mid,step*2);
        insert(mid+1,t,step*2+1);
    }
}

int search(int t,int step)
{
    if(t<a[step].left||t>a[step].right) return 0;
    if(a[step].left==a[step].right)
    {
        if(t==a[step].left) return a[step].num;
    }
    int mid=(a[step].left+a[step].right)/2;
    if(t<=mid) return (t,step*2)+a[step].num;
    else if(t>=mid) return (t,step*2+1)+a[step].num;
}

int main()
{
    return 0;
}
