/*
题意：输入一部字典，输入若干单词
		1.若某个单词能在字典中找到，则输出corret
		2.若某个单词能通过 变换 或 删除 或 添加一个字符后，在字典中找得到，则输出这些单词，输出顺序根据  输入的那部字典的字典序
		3.若某个单词无论操作与否都无法在字典中找得到，则输出空 
分析：暴力，对于判断是否匹配：按长度之差进行分类
		1，strlen(str)==strlen( ch[n] );有可能有一个字符不一样；逐个字符比较，统计不同字符数
		2，strlen(str)+1==strlen( ch[n] );有可能少一个字符，逐个字符比较，如果有字符不同，则ch[n]字符下标往下移动一位，str不变，不同字符数加1
		3，strlen(str)-1==strlen(  ch[n] )有可能少一个字符，逐个字符比较，如果有字符不同，则str]字符下标往下移动一位，ch[n]不变，不同字符数加1 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
char str[33],mp[MAXN+3][33];
int n=0;
vector<int> ans;
bool check(int idx){
	int l1=strlen(str),l2=strlen(mp[idx]),k=0;
	switch(l1-l2){
		case 1:
			for(int i=0,j=0;i<l1;i++){
				if(str[i]!=mp[idx][j])k++;
				else j++;
			}
			break;
		case 0:
			for(int i=0,j=0;i<l1;i++,j++){
				if(str[i]!=mp[idx][j])k++;
			}
			break;
		case -1:
			for(int i=0,j=0;j<l2;j++){
				if(str[i]!=mp[idx][j])k++;
				else i++;
			}
			break;
	}
	return k==1;
}
int main(){
	while(scanf("%s",mp[n])&&strcmp(mp[n],"#")!=0)n++;
	while(scanf("%s",str)&&strcmp(str,"#")!=0){
		ans.clear();int i;
		for(i=0;i<n;i++)
			if(strcmp(str,mp[i])==0){printf("%s is correct\n",str);break;}
		if(i>=n){
			printf("%s:",str);
			for(i=0;i<n;i++)if(check(i))printf(" %s",mp[i]);
			puts("");
		}
	}
	return 0;
}

