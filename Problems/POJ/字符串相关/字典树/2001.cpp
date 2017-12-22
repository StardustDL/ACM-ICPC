/*
Shortest Prefixes
分析：经典Trie，注意数组要开大点 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,NS=26;
#define id(x) (x-'a')
struct Trie{
	int ch[MAXN*26+3][NS],tot,val[MAXN*26+3];
	
	void init(){
		tot=0;
		memset(ch,0,sizeof(ch));
	}
	
	void insert(char* str){
		int cur=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			if(ch[cur][id(str[i])]==0)ch[cur][id(str[i])]=++tot;
			cur=ch[cur][id(str[i])];
			val[cur]++;
		}
	}
	
	void search(char *str){
		int cur=0;
		int len=strlen(str);
		for(int i=0;i<strlen(str);i++){
			if(val[cur]==1)break;
			putchar(str[i]);
			cur=ch[cur][id(str[i])];
		}
	}
}T;
char str[MAXN+3][20+3];
int main(){
	int n=0;
	while(scanf("%s",str[++n])!=EOF)T.insert(str[n]);
	for(int i=1;i<=n;i++){
		printf("%s ",str[i]);
		T.search(str[i]);
		putchar('\n');
	}
	return 0;
}

