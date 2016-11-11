#include<bits/stdc++.h>
using namespace std;
#define Max 6666
int f[Max],t[Max],ans[Max];

int n,p;
int main(){
	cin>>n;
	int maxx=1;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
            t[j]=0;
            maxx++;
        }
		t[f[i]]=1;
		p = f[i];
		ans[p]++;
		for(int j=i+1;j<=n;j++){
			t[f[j]]++;
			if(t[f[j]]>t[p])
				p=f[j];
			if(t[f[j]]==t[p] && p>f[j])
				p=f[j];
			ans[p]++;
		}
	}
	p--;
	for(int i=1;i<=n;i++) if(maxx!=0) cout<<ans[i]<<" ";

	return 0;
}
