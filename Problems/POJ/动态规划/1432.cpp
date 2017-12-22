/*
Decoding Morse Sequences
题意：给出一个字母的译码表，给出一个有n个单词的字典，给出一串编码。问再给出字典中有多少种不同的解码方式。
分析：首先编码只有-和.，可以很方便地建立一棵Trie树，还是最熟悉的二叉方式。
	  然后令opt[i]表示区间[i..len]的方案数
	  	则有opt[i]=sigma{[i..j]组成的单词的个数*opt[j+1]|i<=j<len} 
	  对于求组成的单词个数，这正是Trie的强项 
	  时间复杂度O(n^2) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
typedef bitset<MAXN+3> data;
const char* morse[26] = {
	".-",   "-...", "-.-.", "-..",
	".",    "..-.", "--.",  "....",
	"..",   ".---", "-.-",  ".-..",
	"--",   "-.",   "---",  ".--.",
	"--.-", ".-.",  "...",  "-",
	"..-",  "...-", ".--",  "-..-",
	"-.--", "--.."
};
struct Trie{
	int ch[4*20*MAXN+3][2],cnt[4*20*MAXN+3],tot;
	void init(){
		memset(ch,0,sizeof(ch));
		memset(cnt,0,sizeof(cnt));
		tot=0;
	}
	void insert(const data &d,int len){
		int cur=0;
		for(int i=0;i<len;i++){
			if(!ch[cur][d[i]])ch[cur][d[i]]=++tot;
			cur=ch[cur][d[i]];
		}
		cnt[cur]++;
	}
}T;
int getmorse(char *s,data &d){
	int len=strlen(s),p=0;
	d=0;
	for(int i=0;i<len;i++){
		int tl=strlen(morse[s[i]-'A']);
		for(int j=0;j<tl;j++){
			if(morse[s[i]-'A'][j]=='.')d[p++]=0;
			else d[p++]=1;
		}
	}
	return p;
}
char str[MAXN+3],tmp[MAXN+3];
int n,opt[MAXN+3];
void input(){
	scanf("%s",str);
	scanf("%d",&n);
	T.init();
	data d;
	for(int i=1;i<=n;i++){
		scanf("%s",tmp);
		T.insert(d,getmorse(tmp,d));
	}
}
int dp(){
	int len=strlen(str);
	opt[len]=1;
	for(int i=len-1;i>=0;i--){
		opt[i]=0;
		int cur=0;
		for(int j=i;j<len;j++){
			if(str[j]=='.'){
				if(!T.ch[cur][0])break;
				cur=T.ch[cur][0];
			}
			else{
				if(!T.ch[cur][1])break;
				cur=T.ch[cur][1];
			}
			if(T.cnt[cur]!=0)opt[i]+=T.cnt[cur]*opt[j+1];
		}
	}
	return opt[0];
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",dp());
	}
	return 0;
}

