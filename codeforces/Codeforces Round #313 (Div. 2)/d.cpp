#include <bits/stdc++.h>
using namespace std;
#define Max 233333
char a[Max],b[Max];
bool cmp(int la,int ra,int lb,int rb)
{
	if((ra-la)%2==1)
    {
        for(int i=0; i<(rb-lb); i++)
		{
			if( a[la+i] != b[lb+i] )
				return false;
		}

		return true;
    }
    else
	{
		int mid = (ra-la)/2;

		if( cmp(la,la+mid,lb,lb+mid)==1 && cmp(la+mid,ra,lb+mid,rb)==1 )
			return 1;
		if( cmp(la,la+mid,lb+mid,rb)==1 && cmp(la+mid,ra,lb,lb+mid)==1 )
			return 1;
		else return 0;
	}
}
int main()
{
	scanf("%s%s",a,b);
	if(strcmp(a,b)==0)
	{
		cout<<"YES";
		return 0;
	}
    int lla=strlen(a);
	lla=strlen(a);
	if(cmp(0,lla,0,lla)==true)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
