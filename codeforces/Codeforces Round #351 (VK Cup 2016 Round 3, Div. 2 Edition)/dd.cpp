#include<bits/stdc++.h>
using namespace std;
int m,n;
int a,b,c,d;
int x,y,z,w;
int f[1111];
int g[1111];

void print(int f[1111],int a,int b)
{
	if(f[1]==a)
		for(int i=1;i<=m;i++)
			printf("%d ",f[i]);
	else
		for(int i=m;i>=1;i--)
			printf("%d ",f[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d",&m,&n);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x=a;
	y=b;
	z=c;
	w=d;
	int now;
	if(x>y)swap(x,y);
	if(z>w)swap(z,w);

	if(z==x && y==w)
	{
		f[1]=a;
		f[m]=b;
		now = 1;
		for(int i=2;i<m;i++)
		{
			while(now==a || now==b)
			{
				now++;
			}
			f[i]=now;
			now++;
		}

		{
			print(f,a,b);
			print(f,c,d);
		}
	}
	else
		if(z==x || y==w || z==y ||x==w)
		{
			if(z==x)
			{
				swap(z,w);
				swap(x,y);
			}
			if(z==y)
				swap(z,w);

			if(x==w)
				swap(x,y);

			f[1]=x;
			f[2]=z;
			f[m]=y;
			now = 1;
			for(int i=3;i<m;i++)
			{
				while(now==a||now==b||now==c||now==d)
					now++;
				f[i]=now;
				now++;
			}

			g[1]=z;
			g[2]=x;
			g[m]=w;
			now=1;
			for(int i=3;i<m;i++)
			{
				while(now==a||now==b||now==c||now==d)
					now++;
				g[i]=now;
				now++;
			}

			if(n<m)
				printf("-1\n");
			else
			{
				print(f,a,b);
				print(g,c,d);
			}
		}
		else
		{
			if(m==4 || n<m+1 )
				printf("-1\n");
			else
			{
				f[1]=x;
				f[2]=z;
				f[m-1]=w;
				f[m]=y;

				now=1;
				for(int i=3;i<m-1;i++)
				{
					while(now==a||now==b||now==c||now==d)
						now++;
					f[i]=now;
					now++;
				}

				g[1]=z;
				g[2]=x;
				g[m-1]=y;
				g[m]=w;

				now=1;
				for(int i=3;i<m-1;i++)
				{
					while(now==a||now==b||now==c||now==d)
						now++;
					g[i]=now;
					now++;
				}
				print(f,a,b);
				print(g,c,d);
			}

		}
	return 0;
}
