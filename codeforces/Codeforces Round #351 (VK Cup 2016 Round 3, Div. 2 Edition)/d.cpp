#include<bits/stdc++.h>
using namespace std;
#define Max 1234
int m,n;
int a,b,c,d,x,y,z,w;
int f[Max],g[Max];

void print(int f[Max],int a,int b){
	if(f[1]==a)
		for(int i=1;i<=m;i++)
            cout<<f[i]<<" ";
	else
		for(int i=m;i>=1;i--)
			cout<<f[i]<<" ";
	cout<<endl;
}
int p,kk;
int main(){
    cin>>m>>n;
    cin>>a>>b>>c>>d;
	x=a;y=b;z=c;w=d;
	kk=1;
	if(x>y)swap(x,y);
	if(z>w)swap(z,w);
    int flag=(z==x&&y==w);
    if(!flag){
        if(z==x || y==w || z==y ||x==w)
		{
			if(z==x){
			    swap(x,y);
				swap(z,w);

			}
			if(z==y)
				swap(z,w);
			if(x==w)
				swap(x,y);
			f[1]=x;
			f[2]=z;
			f[m]=y;
			p = 1;
			for(int i=3;i<m;i++)
			{
			    kk++;
				while(p==a||p==b||p==c||p==d)
					p++;
				f[i]=p;
				p++;
			}
            g[2]=x;
			g[m]=w;
			g[1]=z;
			p=1;
			for(int i=3;i<m;i++)
			{
				while(p==a||p==b||p==c||p==d)
					p++;
				g[i]=p;
				p++;
				kk++;
			}

			if(n<m)
				printf("-1\n");
			else if(kk>0)
			{
				print(f,a,b);
				print(g,c,d);
			}
		}
		else
		{
			if(m==4 || n<m+1 )
				cout<<"-1"<<endl;
			else
			{
				f[1]=x;
				f[2]=z;
				f[m-1]=w;
				f[m]=y;
				kk++;

				p=1;
				for(int i=3;i<m-1;i++)
				{
					while(p==a||p==b||p==c||p==d)
						p++;
					f[i]=p;
					p++;
				}

				g[1]=z;
				g[2]=x;
				g[m-1]=y;
				g[m]=w;

				p=1;
				for(int i=3;i<m-1;i++)
				{
					while(p==a||p==b||p==c||p==d)
						p++;
                    kk++;
					g[i]=p;
					p++;
				}
				if(kk>0)
				print(f,a,b);
				print(g,c,d);
			}
		}
    }
	if(flag){
	    p = 1;
	    f[m]=b;
		f[p]=a;
		for(int i=2;i<m;i++){
			while(p==a || p==b){
				p++;
				kk++;
			}
			f[i]=p;
			p++;
		}
		if(kk>0)
        print(f,a,b);
        print(f,c,d);
	}
	return 0;}
