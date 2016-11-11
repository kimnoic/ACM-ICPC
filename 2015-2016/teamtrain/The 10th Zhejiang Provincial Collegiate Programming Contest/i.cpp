#include <bits/stdc++.h>
#define Max 3000010
using namespace std;
char a[Max];
int main(){
    int T;
    cin>>T;
    getchar();
    while(T--){
        gets(a);
        int len=strlen(a);
        int l=len;
        if(len==0)
            printf("00\n");
        else{
            while(l){
                int tmp=l%128;
                l/=128;
                if(l){
                    tmp+=128;
                }
                printf("%02X",tmp);
            }
            for(int i=0; i<len; i++)
                printf("%02X",a[i]);
            printf("\n");
        }
    }
    return 0;
}
