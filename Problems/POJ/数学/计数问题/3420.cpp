/*
题意：4*N的矩形中放入1*2的小矩形有多少种放法 
分析：画画图，可以发现f(n)=f(n-1)+5*f(n-2)+f(n-3)-f(n-4)，f(n)表示n时的答案
	  用矩阵实现
	  矩阵为
	  		1	2	3	4
	  1:	0	0	0	-1
	  2:	1	0	0	1
	  3:	0	1	0	5
	  4:	0	0	1	1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int MOD;
struct Matrix{
	int n,m,dat[5][5];
	Matrix(int n,int m):n(n),m(m){
		memset(dat,0,sizeof(dat));
	} 
	Matrix operator * (const Matrix &M)const{
		Matrix C=Matrix(n,M.m);
		for(int k=1;k<=m;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=M.m;j++)
					(C.dat[i][j]+=dat[i][k]*M.dat[k][j])%=MOD;
		return C;
	}
};
void ksm(Matrix &S,Matrix a,int n){
	while(n>0){
		if(n&1)S=S*a;
		a=a*a;
		n>>=1;
	}
}
Matrix S=Matrix(4,4),K=Matrix(1,4),ans=Matrix(0,0);
int n,m;
int main(){
	S.dat[2][1]=S.dat[3][2]=S.dat[4][3]=1;
	S.dat[3][4]=5;
	S.dat[1][4]=-1;
	S.dat[4][4]=1;
	S.dat[2][4]=1;
	
	K.dat[1][1]=1;
	K.dat[1][2]=5;
	K.dat[1][3]=11;
	K.dat[1][4]=36;
	while(scanf("%d %d",&n,&m),n+m>0){
		MOD=m;
		if(n<4){
			printf("%d\n",K.dat[1][n]%MOD);continue;
		}
		ans=K;
		ksm(ans,S,n-4);
		printf("%d\n",ans.dat[1][4]);
	}
	return 0;
}

