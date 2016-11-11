#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <map>
using namespace std;
#define N 10010
#define Max 1000010
char b[N],a[Max];
int f[N];
int _case,lena,lenb;
int kmp()
{
    int i,j=0,cnt=0;
    for(i=1;i<=lena;i++){
        while(j>0&&b[j+1]!=a[i]) j=f[j];
        if(b[j+1]==a[i]) j+=1;
        if(j==lenb){
             cnt++;
            j=f[j];
        }
    }
    return cnt;
}
int cnt;
int main()
{
	cin>>_case;
	while(_case--)
	{
		scanf("%s%s",b+1,a+1);
		lena=strlen(a+1);
		lenb=strlen(b+1);
		memset(f,0,sizeof(f));

		for(int j=0,i=2;i<=lenb;i++)
		{
			while(j>0&&b[j+1]!=b[i]) j=f[i];
			if(b[j+1]==b[i])j+=1;
			f[i]=j;
		}
		cnt=0;
		for(int i=1,j=0;i<=lena;i++)
		{
			while(j>0&&b[j+1]!=a[i]) j=f[j];
			if(b[j+1]==a[i]) j+=1;
			if(j==lenb)
			{
				cnt++;
				j=f[j];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
