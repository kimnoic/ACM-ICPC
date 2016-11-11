#include <iostream>

using namespace std;

int kmp(char *A,char *B,int *next)
{
    int j=-1,ret=0;
    for(int i=0;A[i];i++)
    {
        while (j!=-1&&A[i]!=B[j+1] ) j=next[j];
        if(!B[j+2])
        {
            ret++;
            j=next[j];
        }
    }
    return ret;
}

void getnext(chat *B,int *next)
{
    next[0]=-1;
    int j=-1;
    for(int i=1;B[i];i++)
    {
        while (j!=-1&&B[i]!=B[j+1]) j=next[j];
        if(B[i]===B[j+1]) j++;
        next[i]=j;
    }
}

int main()
{
    return 0;
}
