#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000
#define N 26
int maxxx,maxcnt;
int s(char t){
    if (t<'a')
        return t-'A';
    else
        return t-'a';
}
char temp[MAXN];
struct Trie{
	int next[MAXN][N],deep[MAXN],cnt[MAXN];
	int root,L;
	int newnode(int d){
		for(int i=0;i<N;i++)
            next[L][i]=-1;
		cnt[L]=0;
		deep[L++]=d+1;
		return L-1;
	}
	void init(){
	    deep[root]=0;
		maxxx=maxcnt=0;
		L=0;
		root=newnode(-1);

	}
	void insert(char buf[]){
		int len=strlen(buf);
		for(int i=0;i<len;i++)
            temp[i]=buf[i];
		for(int i=0;i<len;i++)
			buf[i]=s(temp[len-i-1]);
		int now=root;
		for(int i=0;i<len;i++){
			if (next[now][buf[i]]==-1)
                next[now][buf[i]]=newnode(deep[now]);
			int df=deep[now];
			now=next[now][buf[i]];
			cnt[now]++;
			if (cnt[now]>=3){
				if (deep[now]>maxxx){
					maxxx=deep[now];
					maxcnt=cnt[now];
				}
                else if(deep[now]==maxxx)
                    maxcnt=max(maxcnt,cnt[now]);
			}
		}
	}
}tre;

char buf[MAXN];
int main(){
    int T;
    cin>>T;
    int _case=0;
	while(T--){
		int n;
		cin>>n;
		tre.init();
		for(int i=1;i<=n;i++){
			scanf("%s",buf);
			tre.insert(buf);
		}
		cout<<"Case "<<++_case<<":"<<endl;
		cout<<maxxx<<" "<<maxcnt<<endl;
	}
	return 0;
}
