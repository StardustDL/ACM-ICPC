/*
Text Reverse
题意：单词翻转
分析：读入输出处理 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
char str[1003];
int main(){
	int T,l,i;scanf("%d\n",&T);
	while(T--){
		gets(str);
		l=0,i;
		for(i=0;str[i]!='\0';i++){
			if(str[i]==' '){
				for(int j=i-1;j>=l;j--)putchar(str[j]);
				putchar(' ');
				l=i+1;
			}
		}
		for(i--;i>=l;i--)putchar(str[i]);
		puts(""); 
	}
	return 0;
}

