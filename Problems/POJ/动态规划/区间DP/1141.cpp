/*
Brackets Sequence
题意：给一组小括号与中括号的序列，添加最少的字符，使该序列变为合法序列，输出该合法序列。
分析：用DP构造出最小的值，并记录路径然后即可得到答案
	  具体的：
	  	d[i][j]为输入序列从下标i到下标j最少需要加多少括号才能成为合法序列。0<=i<=j<len (len为输入序列的长度)。
		c[i][j]为输入序列从下标i到下标j的断开位置，如果没有断开则为-1。
		当i==j时，d[i][j]为1
		当s[i]=='(' && s[j]==')' 或者 s[i]=='[' && s[j]==']'时，d[i][j]=d[i+1][j-1]
		否则d[i][j]=min{d[i][k]+d[k+1][j]} i<=k<j ，  c[i][j]记录断开的位置k
		采用递推方式计算d[i][j]
		输出结果时采用递归方式输出print(0, len-1)
		输出函数定义为print(int i, int j)，表示输出从下标i到下标j的合法序列
		当i>j时，直接返回，不需要输出
		当i==j时，d[i][j]为1，至少要加一个括号，如果s[i]为'(' 或者')'，输出"()"，否则输出"[]"
		当i>j时，如果c[i][j]>=0，说明从i到j断开了，则递归调用print(i, c[i][j]);和print(c[i][j]+1, j);
		     如果c[i][j]<0，说明没有断开，如果s[i]=='(' 则输出'('、 print(i+1, j-1); 和")"
             否则输出"[" print(i+1, j-1);和"]" 
      但有一个奇怪的问题：在dp外初始化opt=INF,和在DP内初始化得到答案不同？ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=120;
char str[MAXN+3];
int opt[MAXN+3][MAXN+3],pa[MAXN+3][MAXN+3],n;
void output(int l,int r){
	if(l>r)return;
	if(l==r){
		if(str[l]=='('||str[l]==')')printf("()");
		else if(str[l]=='['||str[l]==']')printf("[]");
		return;
	}
	int c=pa[l][r];
	//cout<<endl<<l<<" "<<r<<" "<<c<<endl;getchar();
	if(c==-1){
		printf("%c",str[l]);
		output(l+1,r-1);
		printf("%c",str[r]);
	}
	else{
		output(l,c);
		output(c+1,r);
	} 
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	memset(pa,-1,sizeof(pa));
	//memset(opt,INF,sizeof(opt));为什么放在外面就不行 
	for(int i=1;i<=n;i++)opt[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int i=1,j;i+len-1<=n;i++){
			j=i+len-1;
			int &t=opt[i][j];t=INF;
			if((str[i]=='('&&str[j]==')' || str[i]=='['&&str[j]==']'))t=opt[i+1][j-1],pa[i][j]=-1;
			for(int k=i,p;k<j;k++){
				if(t>(p=opt[i][k]+opt[k+1][j])){
					t=p;pa[i][j]=k;
				}
			}
		}
	}
	output(1,n);puts(""); 
	return 0;
}

