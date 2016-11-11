#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;
int m,n,mp[30][30],in[30],q[30],flag;
int topsort()
{
	int cnt ,top=0,pos=0,flag=1,tmp[30];
	for(int i=1;i<=n;i++)
	{
		tmp[i]=in[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			//cout<<tmp[j]<<endl;
			if(tmp[j]==0)
			{
				cnt++;
				pos=j;
			}
		}
		if(cnt==0) return 0;
		if(cnt>1) flag=-1;
		q[top++]=pos;
        tmp[pos]=-1;
        for(int j=1;j<=n;j++)
		{
			if(mp[pos][j]) tmp[j]--;
		}
	}
	return flag;
}
int main()
{
	char str[5];
	while(cin>>n>>m)
	{
		flag=0;
		if(m==0&&n==0) break;
		memset(mp,0,sizeof(mp));
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
		{
			cin>>str;
			if(flag) continue;
			int a=str[0]-'A'+1;
			int b=str[2]-'A'+1;
			mp[a][b]=1;
			in[b]++;
			int s=topsort();
			if(s==0)
			{
				//cout<<"asdf";
				printf("Inconsistency found after %d relations.\n",i);
                flag=1;
			}
			if(s==1)
			{
				printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    printf("%c",q[j]+'A'-1);
                printf(".\n");
                flag=1;
			}
		}
		if(!flag) printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
