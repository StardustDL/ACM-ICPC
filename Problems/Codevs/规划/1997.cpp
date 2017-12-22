/*
�����ߵ���ս 
����������DP��opt[i][j][k]��ʾǰi����ս���ɹ�j�Σ�ʣ������Ϊj�ĸ��� 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200,pos=200;
double opt[MAXN+3][MAXN+3][MAXN*2+3],p[MAXN+3];
int a[MAXN+3],n,l,k,mn,mx;
void input(){
	scanf("%d%d%d",&n,&l,&k);
	k=min(k,n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/=100;
	}
	for(int j=1;j<=n;j++)scanf("%d",&a[j]);
}
double dp(){
	mn=mx=k+pos;
	opt[0][0][k+pos]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int t=mn;t<=mx;t++){
				if(opt[i][j][t]==0)continue;//���������Ϊ0����ת�ƣ�����ֻӰ��mx,mn��ȡֵ 
				opt[i+1][j+1][min(t+a[i+1],n+pos)]+=opt[i][j][t]*p[i+1];//�ɹ� 
				opt[i+1][j][t]+=opt[i][j][t]*(1-p[i+1]);//ʧ�� 
				mx=max(mx,min(t+a[i+1],n+pos));
				mn=min(mn,t+a[i+1]);
			}
		}
	}
	double ans=0;
	for(int i=l;i<=n;i++)
		for(int j=pos;j<=mx;j++)
			ans+=opt[n][i][j];
	return ans;
}
int main(){
	input();
	printf("%.6lf",dp());
	return 0;
}

