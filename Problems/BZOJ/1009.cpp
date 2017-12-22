/*
[HNOI2008]GT考试
分析：令f[i][j]表示长度为i，最后j个为不吉利数字的前j个，那么如果求出a[i][j]表示不吉利数字的前i个加一个字符转移到不吉利数字的前j个的方案数
	  那么f[i][j]=sigma{f[i-1][k]*a[k][j]} 可以矩阵乘法
	  那么a怎么求：KMP，
	  每次枚举加哪个字符(0..9)t，令j=i,然后比较第j+1位==t?，等于则a[i][j+1]++，不等则j=fail[j]，注意j等于m的时候不能++，此时不合法，同样，i=[0..m-1] 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=25,INF=0x3f3f3f3f;
typedef int matrix[21][21];
int str[MAXN+3],n,m,K,nxt[MAXN+3];
matrix a,b;
void mul(matrix a,matrix b,matrix ans){
	static matrix tmp;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			tmp[i][j]=0;
			for(int k=0;k<m;k++)(tmp[i][j]+=a[i][k]*b[k][j])%=K;
		}
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			ans[i][j]=tmp[i][j];
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;i++)scanf("%1d",&str[i]);
	for(int i=2,j=0;i<=m;i++){//nxt[0]=nxt[1]=0;j=nxt[1]
		while(j && str[j+1]!=str[i])j=nxt[j];
		nxt[i]=str[i]==str[j+1]?++j:0;//注意要自加，这样下一次就不用j=nxt[i-1]了，并且如果条件不满足，那么j一定等于0 
	}
	for(int i=0;i<m;i++){//i<m
		for(int j=0;j<=9;j++){
			int k=i;
			while(k && str[k+1]!=j)k=nxt[k];
			if(str[k+1]==j)k++;
			if(k==m)continue;
			(b[i][k]+=1)%=K;
		}
	}
	for(int i=0;i<m;i++)a[i][i]=1;
	while(n){
		if(n&1)mul(a,b,a);
		mul(b,b,b);
		n>>=1;
	}
	int ans=0;
	for(int i=0;i<m;i++)(ans+=a[0][i])%=K;
	printf("%d\n",ans); 
	return 0;
}

