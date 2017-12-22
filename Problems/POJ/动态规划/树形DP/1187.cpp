/*
��ʯ������
���⣺����()[]{}�������ֱ�Ϊl1��l2��l3��0<=l1��l2��l3<=10�����涨()��������[]��{}�����棬[]��������{}�����棬��{} [] ()���ȼ��ݼ���������������Ƕ�����Ϊd
         ��0<=d<=30���Ĵ�����һ���ж����ַ�����
���������Ⱥ������뵽���仯dfs��dp[a][b][c][d]��ʾ{}[]()�ֱ���a b c���γ����Ƕ�����Ϊd�ķ�������Ȼ���ҵ���״̬�������鷳����d�Ƕ����������max�õ��ģ�����
          ��dfs�Ĺ�����û�취������һ�������ģ���������ʾ˲��ʯ����
          dp[a][b][c][d]��ʾ{}[]()�ֱ���a b c���γ����Ƕ�����С�ڵ���d�ķ������������ܵõ���״̬���������ȼ�������ı����{}[]()��˳�򼴿ɣ�ö�ٵ�ǰ�����������
          �������{}[]��()�����õ���Ϊdp[a][b][c][d] �C dp[a][b][c][d-1]��d == 0ʱ���Ϊdp[a][b][c][d]������Ϊdfsʱ�ֿ����������Ƕ����ģ����Բ������ظ������� 
		PS��������һ���뷨˵�ĺܺã������ŵ�Ƕ�׿�����һ�����ͼ�Щ���������������Ϊ D��()�ڵ����治����{}[]�ڵ㣬[]�ڵ����治����{}�ڵ㣬Ȼ���������
        ���ΰڷŽڵ㡣
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10,MAXM=30,MOD=11380,INF=0x3f3f3f3f;
int opt[MAXN+3][MAXN+3][MAXN+3][MAXM+3];
int l1,l2,l3,d;
int dp(int l1,int l2,int l3,int d){
	if(l1+l2+l3==0)return opt[l1][l2][l3][d]=1;
	if(d==0)return opt[l1][l2][l3][d]=0;
	int &ans=opt[l1][l2][l3][d];
	if(ans!=-1)return ans;
	ans=0;
	for(int i=0;i<=l3;i++){
		if(i)(ans+=dp(0,0,i-1,d-1)*dp(l1,l2,l3-i,d)%MOD)%=MOD;
		for(int j=0;j<=l2;j++){
			if(j)(ans+=dp(0,j-1,i,d-1)*dp(l1,l2-j,l3-i,d)%MOD)%=MOD;
			for(int k=0;k<=l1;k++)
				if(k)(ans+=dp(k-1,j,i,d-1)*dp(l1-k,l2-j,l3-i,d)%MOD)%=MOD;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&l1,&l2,&l3,&d);
	memset(opt,-1,sizeof(opt));
	int t1=dp(l1,l2,l3,d),t2=0;
	if(d)t2=dp(l1,l2,l3,d-1);
	printf("%d\n",(((t1-t2)%MOD)+MOD)%MOD);
	return 0;
}

