/*
Blocks
���⣺��������ɫ������ȥ��ˢN���ӣ���ʹ��ɫ����ɫ��������Ϊż���ķ����ĸ�����
���������ַ���
		��dp[N][4]����ʾN��ש���Ⱦɫ�����һ��������״̬��
		1.dp[N][0] ����ʾN���к�ɫ��ɫ��������Ϊż����
		2.dp[N][1] ����ʾN���к�ɫΪż������ɫΪ������
		3.dp[N][2] ����ʾN���к�ɫΪ��������ɫΪż����
		4.dp[N][3] ����ʾN���к�ɫ��ɫ��������Ϊ������
		��״̬ת�Ʒ���Ϊ��
			dp[N+1][0] = 2 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 0 * dp[N][3]
			dp[N+1][1] = 1 * dp[N][0] + 2 * dp[N][1] + 0 * dp[N][2] + 1 * dp[N][3]
			dp[N+1][2] = 1 * dp[N][0] + 0 * dp[N][1] + 2 * dp[N][2] + 1 * dp[N][3]
			dp[N+1][3] = 0 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 2 * dp[N][3]
		������ת�Ʒ��̿���ת��Ϊ����
			|2 1 1 0|
			|1 2 0 1|
			|1 0 2 1|
			|0 1 1 2| 
		�����ѧ��
			���û�����ƣ�һ����4 ^ n �Ρ����ڿ����� k �鱻ȾΪ��ɫ����ɫ������k���У�һ���к�ɫ����ɫ�����߾�Ϊ���������������Щ�����ȥ��������Ҫ�Ĵ𰸡���1<= k <= n��
			��n����ѡ��k�飬Ϊc(n, k)�� ����k����ѡ�񲻷��ϵ����Ⱦɫ����Ҫ��k������ż���ۡ�
			���kΪ��������ɫ����ɫ������Ϊһ��һż��2 * ��c(k, 1) + c(k, 3) +  c(k, 5) +������* c(n, k) * 2^(n - k)   ������Ҫ����2������Ϊ���Էֱ�ѡ��졢��ɫΪ������
			���kΪż������ɫ����ɫ������ȫ��Ϊ������ ��c(k, 1) +  c(k, 3) + c(k, 5) +������* c(n, k) * 2^(n - k) �����ﲻ��Ҫ����2��
			��  c(k, 1) +  c(k, 3) + c(k, 5) +���� = 2^��k - 1)
			���ԣ����ı��ʽΪ��
			4^n - 2^n*c(n, 1) - 2^(n - 1)*c(n, 2) - 2^n*c(n, 3) - 2^(n-1)*c(n, 4)-���� = 4^n - 2^n*2^(n-1) - 2^(n-1)*(2^(n-1)-1) = 4^(n-1) + 2^(n-1)
*/
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,MOD=10007;
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
int start[4][4]={{2,1,1,0},{1,2,0,1},{1,0,2,1},{0,1,1,2}};
int n;
int main(){
	for(int i=1;i<=4;i++)memcpy(S.dat[i]+1,start[i-1],sizeof(start[i-1]));
	K.dat[1][1]=1;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n); 
		ans=K;
		ksm(ans,S,n);
		printf("%d\n",ans.dat[1][1]);
	}
	return 0;
}*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=10007;
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		n>>=1;
	}
	return ans;
}
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",(ksm(4,n-1)+ksm(2,n-1))%MOD); 
	}
}


