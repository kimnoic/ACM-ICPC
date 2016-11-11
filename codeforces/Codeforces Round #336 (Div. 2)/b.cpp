#include <bits/stdc++.h>
using namespace std;
#define Max 200010
char a[Max],b[Max];
int s[Max];
int main(){
    scanf("%s %s",a,b);
    int lena=strlen(a);
    int lenb=strlen(b);
    if(b[0]=='1') s[0]=1;
    else s[0]=0;
    for(int i=1;i<lenb;i++){
        s[i]=s[i-1];
        if(b[i]=='1'){
            s[i]++;
        }
    }
    long long sum=0;
    int temp=s[lenb-lena];
    if(a[0]=='1') sum+=(lenb-lena+1)-temp;

    else sum+=temp;
    for(int i=1;i<lena;i++){
        temp=(s[lenb-(lena-i)]-s[i-1]);
        if(a[i]=='1') sum+=((lenb-lena+1)-temp);
        else sum+=temp;
    }
    cout<<sum;
    return 0;
}
