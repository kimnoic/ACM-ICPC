#include <iostream>
#include <string.h>
using namespace std;
string s1,s2;
int l1,l2;
bool look1()
{
    int a=0,b=0;
    for(int i=0;i<=3*l1&&a<l1;i++)
    {
        if(s1[a]==s2[b])
        {
            a++;b++;
        }
        else {
            if(a==0)
                b++;
                a=0;
            }
        if(b==l1) b=0;
    }
    if(a==l1) return true;
    else return false;
}
int main()
{
    while(cin>>s1>>s2)
    {
        l1=s1.size();
        l2=s2.size();
        if(l1!=l2) cout<<"No"<<endl;
        else
        {
            if(look1()) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
