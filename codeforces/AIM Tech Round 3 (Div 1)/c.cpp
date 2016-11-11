#include <bits/stdc++.h>
const int maxn = 1e5+10;
char t[maxn];
int main(){
    std::cin>>t;
    int len=strlen(t);
    int flag=0;
    for(int i=0;i<len;i++){
        if(flag!=2){
            if(i==len-1 && t[i]=='a' &&flag==0){
                printf("z");
            }
            else if(t[i]=='a'){
                printf("a");
                if(flag==1)flag=2;
            }
            else {
                printf("%c",t[i]-1);flag=1;
            }
        }
        else {
            printf("%c",t[i]);
        }

    }
    return 0;
}
