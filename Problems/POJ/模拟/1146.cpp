/*
ID Codes
题意：求一个由小写字母组成的序列的下一个排列
分析：使用next_permutation函数，注意没有后继的情况，此函数会得到第一个排列，判断无下一个排列，字符串完全降序 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;
char str[MAXN+3];
int main(){
	while(scanf("%s",str),str[0]!='#'){
		int flag=0,len=strlen(str);
		for(int i=0;i<len-1;i++){
			if(str[i]<str[i+1]){flag=1;break;}
		}
		if(flag){
			next_permutation(str,str+len);
			printf("%s\n",str); 
		}
		else puts("No Successor"); 
	}
	return 0;
}

