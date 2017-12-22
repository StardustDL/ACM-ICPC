/*
[HNOI2008]GT����
��������f[i][j]��ʾ����Ϊi�����j��Ϊ���������ֵ�ǰj������ô������a[i][j]��ʾ���������ֵ�ǰi����һ���ַ�ת�Ƶ����������ֵ�ǰj���ķ�����
	  ��ôf[i][j]=sigma{f[i-1][k]*a[k][j]} ���Ծ���˷�
	  ��ôa��ô��KMP��
	  ÿ��ö�ټ��ĸ��ַ�(0..9)t����j=i,Ȼ��Ƚϵ�j+1λ==t?��������a[i][j+1]++��������j=fail[j]��ע��j����m��ʱ����++����ʱ���Ϸ���ͬ����i=[0..m-1] 
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
		nxt[i]=str[i]==str[j+1]?++j:0;//ע��Ҫ�Լӣ�������һ�ξͲ���j=nxt[i-1]�ˣ�����������������㣬��ôjһ������0 
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

