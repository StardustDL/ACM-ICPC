/*
[SCOI2007]ѹ��
��������f[i][j][0..1]��ʾ[i..j]ѹ����ʹ��/������M�����Ž�
	  ����ѹ����ʽ��
	  	ֻѹ��ǰk�� 
		�ڵ�k��λ�÷ֳ������֣��ֱ�ѹ�����м�Ӹ�M
		���[i..j]��һ��������������ô��ǰ���һ�벻ʹ��M��ѹ�� ������һ���滻��R 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50,INF=0x3f3f3f3f;
char str[MAXN+3];
int opt[MAXN+3][MAXN+3][2]; 
bool issame(int l,int r){
	int len=r-l+1;
	if(len&1)return false;
	len>>=1;
	for(int i=0;i<len;i++)if(str[l+i]!=str[l+len+i])return false;
	return true;
}
int dp(int l,int r,bool has){
	if(l==r)return 1;
	if(opt[l][r][has])return opt[l][r][has];
	int ans=r-l+1;
	for(int i=l;i<r;i++)ans=min(ans,dp(l,i,has)+r-i);
	if(has)for(int i=l;i<r;i++)ans=min(ans,dp(l,i,1)+1+dp(i+1,r,1));
	if(issame(l,r))ans=min(ans,dp(l,(l+r)>>1,0)+1);
	return opt[l][r][has]=ans;
}
int main(){
	scanf("%s",str);
	printf("%d\n",dp(0,strlen(str)-1,1));//has=1������has=0 
	return 0;
}

