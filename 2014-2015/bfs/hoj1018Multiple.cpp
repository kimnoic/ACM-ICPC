#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define Max 5010
int alp[11],numb[11];
int pro,num,t,top;
int bfs()
{

}
int main()
{
	while(cin>>pro)
	{
		memset(alp,0,sizeof(alp));
		cin>>num;
		while(num--)
		{
			cin>>t;
			alp[t]=1;
		}
		top=1;
		for(int i=1;i<=9;i++)
		{
			if(alp[i]==1)
			{
				numb[top]=i;
				top++;
			}
		}

	}
	return 0;
}
