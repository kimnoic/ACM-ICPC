#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;
#define Max 10000

bool prime[Max];

void cal(){
    int j;
	for(int i=1000;i<=Max;i++){
		for(j=2;j<i;j++){
			if(i%j==0){

				prime[i]=false;
				break;
			}
        }
		if(j==i)
            prime[i]=true;
	}
}

int bfs(int first,int last){
	bool dis[Max];
	queue <int>q;
	int v,temp,vtemp,c[Max],t[4];
	memset(dis,false,sizeof(dis));
	memset(c,0,sizeof(c));
	q.push(first);
	dis[first]=true;
	while(!q.empty()){
		v=q.front();
		q.pop();
		t[0]=v/1000;
		t[1]=v%1000/100;
		t[2]=v%100/10;
		t[3]=v%10;
		for(int j=0;j<4;j++){
			temp=t[j];
			for(int i=0;i<10;i++)
				if(i!=temp){
					t[j]=i;
					vtemp=t[0]*1000+t[1]*100+t[2]*10+t[3];
					if(!dis[vtemp] && prime[vtemp]){
						c[vtemp]=c[v]+1;
						dis[vtemp]=true;
						q.push(vtemp);
					}
					if(vtemp==last) return c[vtemp];
				}
			t[j]=temp;
		}
		if(v==last) return c[v];
	}
	return -1;
}

int main(){
	int n,a,b,key;
	cal();
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		key=bfs(a,b);
		if(key!=-1) printf("%d\n",key);
		else printf("Impossible\n");
	}
	return 0;
}
