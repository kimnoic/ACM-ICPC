#include <iostream>
#include <string.h>

using namespace std;

string s1,s2;
int sum[1001][1001];
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}


int main()
{
    while (cin>>s1>>s2)
    {
        int leng1=s1.size();
        int leng2=s2.size();
        for(int i=0;i<leng1;i++) sum[i][0]=0;
        for(int j=0;j<leng2;j++) sum[0][j]=0;
        for(int i=1;i<=leng1;i++)
        {
            for(int j=1;j<=leng2;j++)
            {
                if(s1[i-1]==s2[j-1]) {sum[i][j]+=sum[i-1][j-1]+1;}
                else sum[i][j]=max(sum[i-1][j],sum[i][j-1]);
            }
        }
        cout<<sum[leng1][leng2]<<endl;
        memset(sum,0,sizeof(sum));
    }
    return 0;
}
