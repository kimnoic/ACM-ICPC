#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;
char g='a';
int y=(int )g;
char s1[100],s2[100];
char t[100];
char gg='\0';

struct node
{
    struct node *l[25];
    char s[100];
};

struct node *r;

void insert(char *s,char *c)
{
    struct node *a,*b;
    int len=strlen(s);
    if(len==0)  return;
    a=r;
    for(int i=0;i<len;i++)
    {
        if(a->l[s[i]-y]!=NULL)
            a=a->l[s[i]-y];
        else
        {
            b=(struct node*)malloc(sizeof(struct node));
            for(int j=0;j<=26;j++)
                b->l[j]=NULL;
            a->l[s[i]-y]=b;
            a=b;
        }
    }
    strcpy(a->s,c);
    return;
}

void search(char *t)
{
    int len=strlen(t);
    if(len==0)return;
    struct node *c=r;
    for(int i=0;i<len;i++)
    {
        if(c->l[t[i]-g]!=NULL)
            c=c->l[t[i]-g];
        else{
            cout<<"eh"<<endl;
            return;
        }
    }
    puts(c->s);
    return;
}


int main()
{
    r=(struct node*)malloc(sizeof(struct node));
    for(int i=0;i<26;i++)r->l[i]=NULL;
    while(gets(s1))
    {
        if(strlen(s1)==0)
            break;
        int i=0;
        while(s1[i]!=' ')i++;
        int k=i;
        while(s1[i]==' ')i++;
        int j=0;
        while(i<strlen(s1))
            s2[j++]=s1[i++];
        s2[j]=gg; s1[k]=gg;
        insert(s2,s1);
    }
    while(gets(t)&&t[0]!=gg)
    {
        search(t);
    }
    return 0;
}
