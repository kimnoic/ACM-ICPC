/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 100001
int f[10010];
void getfill(string s)
{
    memset(f,0,sizeof(f));  //������ǰһ����ĸ�õ�
    for(int i=1;i<s.size();i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}
int find(string a,string s)
{
    int res=0;
    getfill(s);int j=0;
    for(int i=0;i<a.size();i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==s.size()){
            res++;
        }
    }
    return res;
}
int n,m;
char b[Max][9500];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            scanf("%s",a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%s",b[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            for(int j=1;j<=m;j++)
            {
                sum+=find(a[i],b[j]);
            } cout<<sum<<endl;
        }

    }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#define kind 26
using namespace std;
const int MAXN = 10000000;
struct node
{
    int count; //�Ƿ�Ϊ�������һ���ڵ�
    node *next[26];//Trieÿ���ڵ��26���ӽڵ�
    node *fail; //ʧ��ָ��
};
node *q[MAXN]; //���У�����bfs ����ʧ��ָ��
char keyword[10010];//���뵥�� ģʽ��
char a[100000][10000];// ��Ҫ���ҵ� ����
char str[10000];
int head,tail;//���� ͷβָ��
node *root;
int n,m;
void insert(char *word,node *root)
{
     int index,len;
     node *p = root,*newnode;
     len = strlen(word);
     for(int i=0 ;i < len ; i++ )
     {
         index=word[i]-'a';
         if(!p->next[index])//���ַ��ڵ㲻���ڣ�����Trie����
         {
           // ��ʼ�� newnode �� ���� Trie ��
            newnode=(struct node *)malloc(sizeof(struct node));
            for(int j=0;j<26;j++) newnode->next[j]=0;
            newnode->count=0;newnode->fail=0;
            p->next[index]=newnode;
         }
         p=p->next[index];//ָ���ƶ�����һ��
     }
     p->count++;  //���ʽ�β �ڵ� count + 1 �����
}
void build_ac_automation(node *root)
{
     head=0;tail=1;
     q[head]=root;
     node *temp,*p;
     while(head<tail)//bfs���� Trie����ʧ��ָ��
     {
       //�㷨���� kmp �������൱�ڵõ� next[]����
       //�ص����ڣ�ƥ��ʧ��ʱ����failָ����ݵ���ȷ��λ��

        temp=q[head++];
         for(int i=0;i< 26 ;i ++)
         {
             if(temp->next[i])//�ж�ʵ�ʴ��ڵĽڵ�
             {
                 // root �µĵ�һ�� �ڵ� �� ʧ��ָ�붼 ָ��root
                 if(temp==root)temp->next[i]->fail=root;
                 else {
                    //���λ��� �ýڵ�ĸ��ڵ��ʧ��ָ��
                   //֪��ĳ�ڵ��next[i]��ýڵ���ͬ����
                   //�Ѹýڵ��ʧ��ָ��ָ���next[i]�ڵ�
                   //�����ݵ� root ��û���ҵ�����ýڵ�
                   //��ʧ��ָ�� ָ�� root

                    p=temp->fail;//temp Ϊ�ڵ�ĸ�ָ��
                    while(p){
                       if(p->next[i]){
                       temp->next[i]->fail=p->next[i];
                       break;
                       }
                       p=p->fail;
                    }
                    if(!p)temp->next[i]->fail=root;
                 }
                 //ÿ����һ���㣬�Ͱ��������ж��Ӽ�����У�
                 //ֱ������Ϊ��
                 q[tail++]=temp->next[i];
             }
         }
     }
}
int query(node *root)//������ kmp�㷨��
{//iΪ����ָ�룬pΪƥ�䴮ָ��
    int i,cnt=0,index,len=strlen(str);
    node *p=root;
    for(i=0; i < len ;i ++)
    {
       index=str[i]-'a';
      //��ʧ��ָ�����Ѱ�ң��ж�str[i]�Ƿ������Trie����
       while( !p->next[index] && p != root)p=p->fail;
       p=p->next[index];//�ҵ��� p ָ��ýڵ�

       //ָ���Ϊ�գ���û���ҵ���֮ƥ����ַ�

       if(!p)p=root;//ָ�����»ص����ڵ�root���´δ�root��ʼ����Trie��

       node *temp=p;//ƥ��ýڵ������ʧ��ָ����ݣ��ж������ڵ��Ƿ�ƥ��

       while(temp != root )//ƥ�� ��������
       {
           if(temp->count>=0)//�ж� �ýڵ��Ƿ񱻷���
           {
              //ͳ�Ƴ��ֵĵ��ʸ���cnt�����ڽڵ㲻�ǵ��ʽ�βʱcountΪ0��
             //�� cnt+=temp->count; ֻ�� count >0ʱ������ͳ���˵��ʸ���

             cnt+=temp->count;
              temp->count=-1; //����ѷ���
           }
           else break;//�ڵ��ѷ��ʣ��˳�ѭ��
           temp=temp->fail;//����ʧ��ָ�����Ѱ����һ�����������Ľڵ�
       }
    }
    return cnt;
}
int main()
{
    int i,t,n,ans;
    scanf("%d",&t);
    while(t--)
    {
       root=(struct node *)malloc(sizeof(struct node));
       for(int j=0;j<26;j++) root->next[j]=0;
       root->fail=0;
       root->count=0;
       cin>>n>>m;
       for(int i=1;i<=n;i++) scanf("%s",a[i]);
       for(i=0;i<m;i++)
       {
           scanf("%s",keyword);
           insert(keyword,root);
       }
       build_ac_automation(root);
       for(int i=1;i<=n;i++)
       {
           strcpy(str,a[i]);
           ans=query(root);
        printf("%d\n",ans);
        }
    }
    return 0;
}
