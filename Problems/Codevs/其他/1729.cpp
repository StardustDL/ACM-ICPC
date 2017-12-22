/*
单词查找树
分析：普通trie模拟 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int NODE=26,LEN=1000,MAXN=100000,ROOT=0;
typedef char str[LEN+3];
struct trie{
	int ch[MAXN+3][NODE+1],tot;
	char c[MAXN*NODE+3];
	void init(){
		memset(ch,0,sizeof(ch));tot=1;
	}
	int id(char t){return t-'A';}
	void insert(str s){
		int cur=ROOT;
		for(int i=0;i<strlen(s);i++){
			if(ch[cur][id(s[i])]==0)
				ch[cur][id(s[i])]=++tot;
			cur=ch[cur][id(s[i])];
		}
	}
}tree;
str s;
int main(){
	tree.init();
	while(cin>>s)tree.insert(s);
	cout<<tree.tot<<endl;
	return 0;
}
