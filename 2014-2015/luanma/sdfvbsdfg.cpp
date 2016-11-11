#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;

struct dict{
	char from[11], to[11];
	int next;
}s[maxn];

int hashIndex[maxn];

int DJBHash(char* S){
	int hash = 5381;
	int d = strlen(S);
	for(int i = 0; i < d; i++)	hash = ((hash << 5) + hash) + S[i];
	return hash % (100000 + 7);
}

void find(char* S){
	if(S[0] == '\0')	return;
	int hash = DJBHash(S);
	for(int i = hashIndex[hash]; i; i = s[i].next){
		if(!strcmp(s[i].from, S))	{ puts(s[i].to); return; }
	}
	puts("eh");
}

int main(){
	char buffer[22];
	int k = 1;
	memset(hashIndex, 0, sizeof hashIndex);
	while(gets(buffer)){
		if(buffer[0] == '\0')	break;
		sscanf(buffer, "%s %s", s[k].to, s[k].from);
		int hash = DJBHash(s[k].from);
		s[k].next = hashIndex[hash];
		hashIndex[hash] = k++;
	}
	while(gets(buffer))	find(buffer);
	return 0;
}
