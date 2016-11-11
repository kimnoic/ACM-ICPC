#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXV 1010

int r,c;
bool map[MAXV][MAXV],use[MAXV];
int vx[MAXV],vy[MAXV];

bool dfs(int x){
	int i;
	for(i=1;i<=c;i++){
		if(map[x][i] && !use[i]){
			use[i]=1;
			if(vy[i]==-1 || dfs(vy[i])){
				vy[i]=x;
				vx[x]=i;
				return true;
			}
		}
	}
	return false;
}

int hungary(){
	int i,num=0;
	memset(vx,-1,sizeof(vx));
	memset(vy,-1,sizeof(vy));
	for(i=1;i<=r;i++){
		if(vx[i]==-1){
			memset(use,0,sizeof(use));
			if(dfs(i)) num++;
		}
	}
	return num;
}

int main(){
	int i,a,b,Case,j;
	scanf("%d",&Case);
	while(Case--){
		scanf("%d%d",&r,&c);
		memset(map,0,sizeof(map));
		for(i=1;i<=c;i++){
			scanf("%d%d",&a,&b);
			map[a][i]=1;
			map[b][i]=1;
		}
		if(c<r || hungary()!=r){
			printf("NO\n");
		}else{
			for(j = 1;j <= c;j++)
				if(vy[j] != -1)
					 printf("%d ",vy[j]);
				 else
					 for(i=1;i<=r;i++)
						 if(map[i][j]){
							 printf("%d ",i);
							 break;
						}
			printf("\n");
		}
	}
	return 0;
}
