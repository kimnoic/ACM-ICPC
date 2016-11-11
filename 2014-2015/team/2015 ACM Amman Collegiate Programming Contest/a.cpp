#include <bits/stdc++.h>
using namespace std;
string s1,s;
int main()
{
    int T;
    cin>>T;
    int n;
    char res[23];int re,r;
    char name[23];
    int num,time;
    while(T--)
    {
        cin>>n;
        cin>>res>>re>>r;
        for(int i=1;i<n;i++)
        {
            cin>>name>>num>>time;
            if(num<re||(num==re&&time>=r)) continue;
            strcpy(res,name);
            re=num;r=time;
        }
        cout<<res<<endl;
    }
    return 0;
}
