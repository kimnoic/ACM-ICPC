#include <bits/stdc++.h>
using namespace std;
#define M 34
bool mp[30],flag;
int a[23][23];
void dfs(int x,int y,int k){
	if(x==4&&y>=2){
		int sum=0;
		for(int t=1;t<=4;t++)
            sum+=a[t][y-1];
		if(sum!=M)
            return;
	}
	if(y==1&&x>=2){
		int sum=0;
		for(int t=1;t<=4;t++)
			sum+=a[x-1][t];
		if(sum!=M)
            return;
	}
	if(x==5){
		flag=true;
		printf("Case %d:\n",k);
		for(int i=1;i<=4;i++){
			for(int j=1;j<=3;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<a[i][4]<<endl;
		}
		return;
	}
	if(a[x][y]==-1){
		for(int i=1;i<=16;i++){
			if(flag)
                return;
			if(mp[i]){
                mp[i]=false;
				a[x][y]=i;
				if(y!=4)
					dfs(x,y+1,k);
				else
                    dfs(x+1,1,k);
				a[x][y]=-1;
				mp[i]=true;
			}
		}
	}
	else{
		if(y!=4)
            dfs(x,y+1,k);
		else
            dfs(x+1,1,k);
	}
}
int main(){
	int T;
	cin>>T;
	int _case=0;
	while(T--){
	    memset(mp,true,sizeof(mp));
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				cin>>a[i][j];
				if(a[i][j]!=-1)
                    mp[a[i][j]]=false;
			}
		}
		flag=false;
		dfs(1,1,++_case);
	}
	return 0;
}
