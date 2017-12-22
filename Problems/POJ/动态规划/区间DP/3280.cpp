/*
Cheapest Palindrome
���⣺����m���ַ���������n���ַ���ÿ���ַ���������ֵ���ֱ�������һ���������ַ��Ĵ��ۣ�ɾ��һ���������ַ��Ĵ��ۣ�������ԭ�ȸ������Ǵ��ַ���ɻ��Ĵ�����С���ۡ�
������dp[i][j]��������i������j��Ϊ���Ĵ�����С���ۣ���ô����dp[i][j]�����������
		1��dp[i+1][j]��ʾ����i������j�Ѿ��ǻ��Ĵ��˵���С���ۣ���ô����s[i]�����ĸ�����������ֲ�����ɾ������ӣ���Ӧ�����ִ��ۣ�dp[i+1][j]+add[s[i]],dp[i+1][j]+del[s[i]]��ȡ�����ִ��۵���Сֵ��
		2��dp[i][j-1]��ʾ����i������j-1�Ѿ��ǻ��Ĵ��˵���С���ۣ���ô����s[j]�����ĸ��ͬ�������ֲ�����dp[i][j-1]+add[s[j]],dp[i][j-1]+del[s[j]]��ȡ��Сֵ
		3������s[i]==s[j]��dp[i+1][j-1]��ʾ����i+1������j-1�Ѿ��ǻ��Ĵ�����С���ۣ���ô����������������ǿ���dp[i][j]��dp[i+1][j-1]�Ĵ�С
		Ȼ��dp[i][j]ȡ������Щ�������Сֵ 
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
