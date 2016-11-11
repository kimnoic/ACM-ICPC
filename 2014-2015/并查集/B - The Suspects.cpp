#include <iostream>

using namespace std;

#define Max 30002

int father[Max],tree[Max];

void build (int a)
{
    for(int i=0;i<a;i++)
    {
        father[i]=i;
        tree[i]=1;
    }
}

int path(int a)
{
    if(a!=father[a])
    {
        father[a]=path(father[a]);
    }
    return father[a];
}

void together(int a,int b)
{
    a=path(a);b=path(b);
    if(a==b) return ;
    else if(tree[a]>=tree[b])
    {
        father[b]=a;
        tree[a]+=tree[b];
    }
    else
    {
        father[a]=b;
        tree[b]+=tree[a];
    }
}
int main()
{
    int n,m;
    while (cin>>n>>m&&(n!=0||m!=0))
    {
        build(n);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b;
            for(int j=1;j<a;j++)
            {
                cin>>c;
                together(b,c);
            }
        }
        cout<<tree[father[0]]<<endl;
    }
    return 0;
}
