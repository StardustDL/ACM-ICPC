/*
IMMEDIATE DECODABILITY
题意：给若干个01字符串，问是否有一个是另外一个的前缀？ 
分析：Trie走起 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct Trie{
	int ch[MAXN+3][2],tot,val[MAXN+3];
	void init(){
		tot=0;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
	}
	bool insert(char* str){
		int cur=0;
		for(int i=0;str[i]!='\0';i++){
			if(ch[cur][str[i]-'0']==0)ch[cur][str[i]-'0']=++tot;
			cur=ch[cur][str[i]-'0'];
			if(val[cur]==1)return false;
		}
		val[cur]=1;
		return true;
	}
}T;
char str[103];
int main(){
	int kase=0;
	T.init();
	while(~scanf("%s",str)){
		if(str[0]=='9'){
			printf("Set %d is immediately decodable\n",++kase);
			T.init();
			continue;
		}
		if(!T.insert(str)){
			printf("Set %d is not immediately decodable\n",++kase);
			while(scanf("%s",str),str[0]!='9');
			T.init();
		}
	}
	return 0;
}

