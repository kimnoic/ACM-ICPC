#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>


using namespace std;
int judge(string a,string b)
{
    if(a.size()==b.size())
	{
        for(int i=0;i<a.size();i++)
            if(b[i]>a[i]) return -1;
        return 1;
	}
    for(int i=0;i<b.size();i++)
        if(b[i]>a[i]) return 0;
    return 1;
}
string f(string a,string b,int i,int j)
{
    string s;
    int flag=0,k=0,p=i+1;
    char ch[2009];
    for( ; i>=0 && j>=0; i--,j--){
        if(!flag){
            if(a[i]>= b[j])
                ch[k++]='0'+(a[i]-b[j]);
            else {
                ch[k++]=b[j];
                if(a[i-1]=='0') flag=1;
                else a[i-1]--;
            }
            continue;
        }
        if(a[i]==b[j]){
            ch[k++]='1'; continue;
        }
        if(a[i] > b[j]){
            ch[k++]='0'; flag=0; continue;
        }
        if(a[i] < b[j]){
            ch[k++]='0'; a[i-1]--; continue;
        }
    }
    int mark=0;
    for(int i=k-1;i>=0;i--) {
        if(!mark && ch[i]=='0') continue;
        s+=ch[i];
        mark=1;
    }
    if(mark)
        for(int i=p;i<a.size();i++)
            s+=a[i];
    else {
        int ans=0;
        for(int i=p;i<a.size();i++){
            if(!ans && a[i]=='0') continue;
            ans=1;
            s+=a[i];
        }
    }
    if(s.size()==0) return "0";
    return s;
}

string fan(string a,string b)
{
    if(a.size()<b.size()) return a;
    while(a.size()>=b.size()){
        if(a==b) return "0";
        if(judge(a,b)>0)
            a = f(a,b, b.size()-1, b.size()-1);
        else if(!judge(a,b))
            a = f(a,b, b.size(), b.size()-1);
        else break;
    }
    return a;
}
string gcd(string a,string b){
    if(b=="0") return a;
    return gcd(b,fan(a,b));
}



int main()
{
    int t;
    cin>>t;
    int d=1;
    while(t--)
	{
        string a,b;
        cin>>a>>b;
        string c=gcd(a,b);
        cout<<"Case #"<<d<<": "<<c<<endl;
        d++;
	}
}
