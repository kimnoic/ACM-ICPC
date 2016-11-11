#include <iostream>
#include <string.h>
using namespace std;
#define Max 510
int a[Max],b[Max];
int f[Max];
int main()
{
	int t;
	cin>>t;
	int aa,bb;
	while(t--)
	{
		memset(f,0,sizeof(f));
		cin>>aa;
		for(int i=1;i<=aa;i++) cin>>a[i];
		cin>>bb;
		for(int i=1;i<=bb;i++) cin>>b[i];
		int ans=0;
		for(int i=1;i<=aa;++i)
		{
			int maxf=0;
			for(int j=1;j<=bb;++j)
			if(b[j]<a[i]) maxf=max(maxf,f[j]);
			else
				if(b[j]==a[i]) f[j]=maxf+1,ans=max(ans,f[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
