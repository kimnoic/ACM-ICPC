#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x3ffffffff
#define Max 200010
char a[Max],b[Max];
int aa[30][30]={};
int pl=-1,pr=-1;
int n;
int main()
{
	cin>>n;
	cin>>a>>b;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			int x=a[i]-'a';
			int y=b[i]-'a';
			aa[x][y]=i+1;
			cnt++;
		}
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
	{
		if(aa[i][j]&&aa[j][i])
		{
			cout<<cnt-2<<endl;
			cout<<aa[i][j]<<" "<<aa[j][i];
			return 0;
		}
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(aa[i][j])
		{
			for(int k=0;k<26;k++)
				if(aa[j][k])
			{
				cout<<cnt-1<<endl;
				cout<<aa[i][j]<<" "<<aa[j][k];
				return 0;
			}
		}
		cout<<cnt<<endl;
		cout<<"-1 -1";
	return 0;
}
