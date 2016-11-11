#include <iostream>
#include <string.h>
using namespace std;
#include <math.h>
int num[27]={};
int num2[27]={};
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
bool judge(int a)
{
    if(a==0||a==1) return false;
    else if(a==2) return true;
    else
    {int t=0;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) {t++;break;}
    }
    if(t==1) return false ;
    else  return true;}
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        num[(int)s[i]-96]++;
        num2[(int)s[i]-96]=1;
    }
    int maxx=0;
    int minn=100;
    for(int i=1;i<=26;i++)
    {
        if(num2[i]!=0)
        {
            maxx=max(maxx,num[i]);
            minn=min(minn,num[i]);
        }
    }
    if(judge(maxx-minn)) cout<<"Lucky Word"<<endl<<maxx-minn;
    else cout<<"No Answer"<<endl<<"0";
    return 0;
}
