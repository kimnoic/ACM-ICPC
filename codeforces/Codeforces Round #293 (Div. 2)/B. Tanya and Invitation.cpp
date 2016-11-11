#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
char a[233333],b[233333];
int alpa[100]={};
int alpb[100]={};
int main()
{
	cin>>a>>b;
	int lena=strlen(a);
	int lenb=strlen(b);
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='a') alpa[a[i]-'a'+1]++;
		else alpa[a[i]-'A'+27]++;
	}
	for(int i=0;i<lenb;i++)
	{
		if(b[i]>='a') alpb[b[i]-'a'+1]++;
		else alpb[b[i]-'A'+27]++;
	}
	int suma=0,sumb=0;
	for(int i=1;i<=60;i++)
	{
		if(alpa[i]>alpb[i])
		{
			suma+=alpb[i];
			alpa[i]-=alpb[i];
			alpb[i]=0;
		}
		else
		{
			suma+=alpa[i];
			alpb[i]-=alpa[i];
			alpa[i]=0;
		}
	}
	for(int i=1;i<=26;i++)
	{
		sumb+=min(alpa[i],alpb[i+26]);
	}
	for(int i=27;i<=52;i++)
	{
		sumb+=min(alpa[i],alpb[i-26]);
	}
	cout<<suma<<" "<<sumb;
	return 0;
}
