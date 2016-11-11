#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
int fa[105];
using namespace std;
struct edge
{
    int u,v,w;
}e[105*105];
struct line
{
	int pre,cur;
}te[105];
bool cmp(edge a,edge b)
{
    if (a.w>b.w) return false;
    return true;
}
int find(int x)
{
    if (fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
	int _case;
	cin>>_case;
	while(_case--)
    {int i,j,m,n,k,u,v,w,cnt,ans;
    scanf("%d%d",&n,&m);
    cnt=0;
    for (i=1;i<=n;i++)  fa[i]=i;
        for (i=1;i<=m;i++)
        {

            scanf("%d%d%d",&u,&v,&w);
            e[cnt].u=u;
            e[cnt].v=v;
            e[cnt].w=w;
            cnt++;
        }
    sort(e,e+cnt,cmp);
    k=0;i=0;ans=0;
    while (k<n-1)
    {
        if (i==cnt) break;
        if (find(e[i].u)!=find(e[i].v))
        {
            k++;
            te[k].cur=i;
            ans+=e[i].w;
            fa[find(e[i].u)]=find(e[i].v);
        }
        i++;
    }
    int sum=0;
    int flag=0;
    for(j=1;j<=k;j++)
	{
		sum=0;
		for (i=1;i<=n;i++)  fa[i]=i;
		sort(e,e+cnt,cmp);
		int kk=0;i=0;sum=0;
		while (kk<n-1&&i<=m)
		{
			i++;
			if (i==te[j].cur) continue;
			if (find(e[i].u)!=find(e[i].v))
			{
				kk++;
				sum+=e[i].w;
				fa[find(e[i].u)]=find(e[i].v);
			}
		}
		if(kk!=n-1) continue;
		if(sum==ans) {flag=1;break;}
	}

    if(flag==0) cout<<ans<<endl;
    else cout<<"Not Unique!"<<endl;}
    return 0;
}
