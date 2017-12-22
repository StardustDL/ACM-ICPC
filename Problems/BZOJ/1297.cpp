/*
[SCOI2009]��·
���⣺����һ���ڽӾ�����1~n�ı�Ȩǡ��ΪT��·����������Ȩ[1..9]
	  ���ǵ����б�Ȩ����1��ʱ�� ��ô��Ȼ�ڽӾ����Գ�T��֮��a[1][n]���Ǵ�
		��Ϊ����ȨΪ1��ʱ��a[i][j]���Ա�ʾ�ӵ�i����ת�Ƶ���j����ķ����� ��Ȼ������Ͼس˵Ķ���
		���ڱ�Ȩ���Ϊ9 ��ô��һ������9�� ��i�����ɵĵ�j+1�������j������һ����ȨΪ1�ı� 
		��ôi->j��һ����ȨΪk�ıߵȼ���i��j��ɵĵ�k�������� 
		������㲻���൱���ǰѱ߱���˵㣬ͬʱ��֤�˵�Ĺ�ģ����O(n)�ġ�
	  ע������ά��n,m��ע�ⵥλ���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=2009;
int n,t;
struct matrix{
	int d[10*10][10*10];
	int n,m;
	int* operator [](int x){return d[x];}//һ��С���� 
	void clear(){memset(d,0,sizeof(d));}
}mp,temp,Ans;
void multiply(matrix &a,matrix &b,matrix &c){
	c.clear();c.n=a.n;c.m=b.m;
	for(int i=1;i<=a.n;i++)
		for(int j=1;j<=b.m;j++)
			for(int k=1;k<=a.m;k++)
				(c[i][j]+=a[i][k]*b[k][j])%=MOD;
}
void quickpow(matrix &a,matrix &ans,int n){
	while(n){
		if(n&1){multiply(ans,a,temp);ans=temp;}
		n>>=1;
		multiply(a,a,temp);a=temp;
	}
}
#define P(x,y) ((y-1)*n+x)
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		for(int j=2;j<=9;j++)mp[P(i,j)][P(i,j-1)]=1;
	for(int i=1;i<=n;i++){
		for(int j=1,k;j<=n;j++){
			scanf("%1d",&k);
			if(k==0)continue;
			mp[i][P(j,k)]=1;
		}
	}
	mp.n=mp.m=Ans.n=Ans.m=9*n;
	for(int i=1;i<=9*n;i++)Ans[i][i]=1;
	quickpow(mp,Ans,t);
	printf("%d\n",Ans[1][n]);
	return 0;
}

