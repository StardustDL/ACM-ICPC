/*
Digital Roots
题意：把数的每个位数相加，看是否小于10，是就输出，否则继续。 
分析：可以暴力，也可以根据以下结论：n的数根k=(n-1)%9+1;
	  原因：根以9为循环节
	  注意输入的数字很大需要字符串读入，先进行按位求和，再计算 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
char s[MAXN+3];
int main(){
	while(gets(s),s[0]!='0'){
		int n=0; 
		for(int i=0;s[i]!='\0';i++)n+=s[i]-'0';
		printf("%d\n",(n-1)%9+1);
	}
	return 0;
}

