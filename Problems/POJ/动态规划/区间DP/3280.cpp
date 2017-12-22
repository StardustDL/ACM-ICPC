/*
Cheapest Palindrome
题意：给你m个字符，其中有n种字符，每种字符都有两个值，分别是增加一个这样的字符的代价，删除一个这样的字符的代价，让你求将原先给出的那串字符变成回文串的最小代价。
分析：dp[i][j]代表区间i到区间j成为回文串的最小代价，那么对于dp[i][j]有三种情况：
		1、dp[i+1][j]表示区间i到区间j已经是回文串了的最小代价，那么对于s[i]这个字母，我们有两种操作，删除与添加，对应有两种代价，dp[i+1][j]+add[s[i]],dp[i+1][j]+del[s[i]]，取这两种代价的最小值；
		2、dp[i][j-1]表示区间i到区间j-1已经是回文串了的最小代价，那么对于s[j]这个字母，同样有两种操作，dp[i][j-1]+add[s[j]],dp[i][j-1]+del[s[j]]，取最小值
		3、若是s[i]==s[j]，dp[i+1][j-1]表示区间i+1到区间j-1已经是回文串的最小代价，那么对于这种情况，我们考虑dp[i][j]与dp[i+1][j-1]的大小
		然后dp[i][j]取上面这些情况的最小值 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define id(x) ((x)-'a'+1)
using namespace std;
const int MAXN=2000; 
int opt[MAXN+3][MAXN+3],add[27],del[27],n,m;
char s[MAXN+3],ch[10];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
    	scanf("%s",ch);
    	scanf("%d%d",&add[id(ch[0])],&del[id(ch[0])]);
    }
    memset(opt,0,sizeof(opt));
    for(int i=m-1;i>=1;i--){
        for(int j=i+1;j<=m;j++){
            opt[i][j]=min(opt[i+1][j]+min(add[id(s[i])],del[id(s[i])]),opt[i][j-1]+min(add[id(s[j])],del[id(s[j])]));
            if(s[i]==s[j])opt[i][j]=min(opt[i][j],opt[i+1][j-1]);
        }
    }
    printf("%d\n",opt[1][m]);
    return 0;
}
